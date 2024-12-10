// Write a function to verify if the check digit of a CAS number is correct
// gcc -o cas_checkdigit cas_checkdigit.c

#include <stdio.h>
#include <string.h>

int validate_cas(char *cas) {
    int sum = 0, c = 1;
    for (int i=strlen(cas)-2; i >= 0; i--) {
        if (cas[i] != '-') {
            sum += c * (cas[i] - 48);
            c++;
        }
    }
    return sum % 10 == cas[strlen(cas)-1] - 48;
}

int main() {
    printf("77-86-1: %d\n", validate_cas("77-86-1"));
    printf("77-86-2: %d\n", validate_cas("77-86-2"));
    printf("56-40-6: %d\n", validate_cas("56-40-6"));
    printf("50-00-0: %d\n", validate_cas("50-00-0"));
}
