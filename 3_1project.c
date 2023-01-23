#include "2primetools.c"
#include <stdio.h>

#define NUMBERARG 600851475143

int largestprimefactor(long long int);

int main() {
    printf("The largest prime factor of %lld is: %d.\n", NUMBERARG, largestprimefactor(NUMBERARG));
}

int largestprimefactor(long long int N) { //recursive definition leads to repeated tests involving small prime numbers: redundant.
    if (isprime(N))
        return N;

    int otherprime, currentprime, primeindex = 1;

    while (1) {
        currentprime = getnthprime(primeindex++);
        if (N % currentprime == 0) {
            printf("Prime factor found: %d\n", currentprime);
            otherprime = largestprimefactor(N / currentprime);
            return (currentprime > otherprime) ? currentprime : otherprime;
        }
    }
}
