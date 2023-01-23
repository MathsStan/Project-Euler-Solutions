#include <stdio.h>
#include <stdlib.h>

#define MAXPRIMES 10000
#define NUMBERARG 600851475143
/* construct a list of primes and check if any are divisors of our number */
/* If a divisor is found, update largest prime divisor if nescary and then repeat process with now divided number. */

//NOTE! there is likely a quicker way to do this as my current solution loops through the list of primes far too many times.
struct prime {int p; struct prime *next;};
enum bool {FALSE, TRUE};

struct prime *sieve;

void printprimes(struct prime *, int);
enum bool isprime(struct prime *, int);
struct prime *newprime(int);
int largestprimefactor(long long int, int);

int main() {
    sieve = newprime(2);
    printf("The largest prime factor of %lld is %d.\n", NUMBERARG,  largestprimefactor(NUMBERARG, 1));
    //printprimes(sieve, MAXPRIMES);
}

struct prime *newprime(int p) {
    struct prime *newprimeptr = NULL;
    newprimeptr = (struct prime *) malloc(sizeof(struct prime));

    newprimeptr->p = p;
    newprimeptr->next= NULL;
}
 
void printprimes(struct prime *sieve, int maxnumber){
    int i;
    struct prime *currentprime;

    if (sieve == NULL)
        exit(-1);
    for (i=0, currentprime = sieve; currentprime != NULL && i < maxnumber; i++, currentprime = currentprime->next)
        printf("prime number %d is %d\n", i + 1, currentprime->p);
}

int largestprimefactor(long long int n, int P) {
    //go through every prime, calculating more primes if need be.
    //  if any prime p divides n, check if p is greater than the current largest divisor, then rerun on n/p.
    //we are using the assumption that all previously constructed primes contain no missing primes.
    int i;
    struct prime *currentprimeptr;

    for (currentprimeptr = sieve; currentprimeptr != NULL; currentprimeptr = currentprimeptr->next) {
        i = currentprimeptr->p;
        if (n == i)
            return (i > P) ? i : P;
        if (n%i == 0)
            return largestprimefactor(n/i, (i>P) ? i : P);
        if (currentprimeptr->next == NULL) {
            //Append a new prime
            while (!isprime(sieve, ++i))
                ;
            currentprimeptr->next = newprime(i);
        }
    }
}

enum bool isprime(struct prime *sieve, int p) {
    struct prime *currentprimeptr;

    for (currentprimeptr = sieve; currentprimeptr != NULL && p % currentprimeptr->p != 0; currentprimeptr = currentprimeptr->next)
        ;
    if (currentprimeptr == NULL) //for loop completed, no primes were divisors
        return TRUE;
    return FALSE;
}


