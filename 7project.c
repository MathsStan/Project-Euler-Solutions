#include "primetools.c"
#include <stdio.h>

#define TARGETPRIMENO 10001

int main() {
    printf("The %dst prime number is: %d", TARGETPRIMENO, getnthprime(TARGETPRIMENO));
}






