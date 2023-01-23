#include <stdio.h>
#include <stdlib.h>

struct prime {int p; struct prime *next;};
enum bool {FALSE, TRUE};

struct prime *sieve;

struct prime *newprime(int);
void printprimes(int);
enum bool unfinished_isprime(int);
enum bool isprime(int);
int nextprime(struct prime *);

struct prime *newprime(int p) {
    struct prime *newprimeptr = NULL;
    newprimeptr = (struct prime *) malloc(sizeof(struct prime));

    newprimeptr->p = p;
    newprimeptr->next= NULL;
}


void printprimes(int maxnumber){
    int i;
    struct prime *currentprime;

    if (sieve == NULL)
        exit(-1);
    for (i=0, currentprime = sieve; currentprime != NULL && i < maxnumber; i++, currentprime = currentprime->next)
        printf("prime number %d is %d\n", i + 1, currentprime->p);
}

/*
enum bool isprime(struct prime *sieve, int p) {
    struct prime *currentprimeptr;

    for (currentprimeptr = sieve; currentprimeptr != NULL && p % currentprimeptr->p != 0; currentprimeptr = currentprimeptr->next)
        ;
    if (currentprimeptr == NULL) //for loop completed, no primes were divisors
        return TRUE;
    return FALSE;
}
*/

enum bool unfinished_isprime(int n) {
    struct prime *primeptr;
    int p;

    if (sieve == NULL)
        exit(-1);
    for (primeptr = sieve; primeptr != NULL; primeptr = primeptr->next) {
        p = primeptr->p;
        if (p > n)
            return TRUE;
        if (n % p == 0)
            return FALSE;
    }
    return TRUE;
}

enum bool isprime(int n) {
    struct prime *primeptr;
    int p;

    if (sieve == NULL)
        exit(-1);
    for (primeptr = sieve; primeptr != NULL; primeptr = primeptr->next) {
        p = primeptr->p;
        if (p > n)
            return TRUE;
        if (n % p == 0)
            return FALSE;
        if (primeptr->next == NULL){
            nextprime(primeptr);
        }
    }
}

int nextprime(struct prime *primeptr) {
    int i;
    
    if (sieve == NULL || primeptr == NULL)
        exit(-1);
    if (primeptr->next != NULL)
        return primeptr->next->p;

    
    i = primeptr->p;
    while (!unfinished_isprime(++i))
        ;
    primeptr->next = newprime(i);
    return i;
}
