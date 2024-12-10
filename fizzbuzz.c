// Write a function to count from 1 to N, divisible of 3 print fizz, divisible of 5 print buzz, divisible of both print fizzbuzz

#include <stdio.h>

void fizzbuzz(int num) {
    for (int i=1; i < num; i++) {
        if (i % 3 == 0) printf("fizz");
        if (i % 5 == 0) printf("buzz");
        if (i % 3 != 0 && i % 5 != 0) printf("%d", i);
        printf("\n");
    }
}

int main() {
    fizzbuzz(100);
}
