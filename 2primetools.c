#include <stdio.h>

#define MAXPRIMES 10000

/* 

Set of basic functions for obtaining prime numbers.

primes are stored in a large array of ints (so a bound of 2^31 - 1 for the largest prime)

*/
enum bool {FALSE, TRUE};

int primes[MAXPRIMES] = {2, 0};
int discovered_primes_count = 1;


int getnthprime(int n) {
    int newprime, primeindex;

    if (n <= discovered_primes_count) {
        //printf("No need to calculate more primes! We have discovered %d primes already. ", discovered_primes_count);
        return primes[n - 1];
    }

    //printf("AAH! We need new primes!\n");
    for (newprime = primes[discovered_primes_count - 1] + 1; n > discovered_primes_count; newprime++) {
        //printf("newprime = %d\n", newprime);
        for (primeindex = 0; primeindex < discovered_primes_count; primeindex++) {
            if (newprime % primes[primeindex] == 0)
                break;
        }
        if (primeindex >= discovered_primes_count) { //<==> all currently stored primes do not divide our newprime.
            primes[discovered_primes_count++] = newprime;
        }
    }
    return newprime - 1; //could also return getnthprime(n) as the discovered primes count should now equal n.
}

enum bool isprime(int n) {
    int primecounter = 1, currentprime;

    while (TRUE) {
        currentprime = getnthprime(primecounter++);
        if (n == currentprime)
            return TRUE;
        else if (n < currentprime)
            return FALSE;
    }
}

/*
int main() {
    int i;
    printf("is %d a prime? %s\n", 24, (isprime(24) ? "YES!" : "NO!"));
    for (i = 1; i < 10; i++)
        printf("Prime number %d is: %d\n", i, getnthprime(i));
}
*/