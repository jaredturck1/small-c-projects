// find the largest number of repeating 0s in a given binary string
// gcc -o consecutive_zeros consecutive_zeros.c

#include <stdio.h>
#include <string.h>

int consecutive_zeros(char *txt) {
    char *token;
    int len;
    int max = 0;

    char new_txt[strlen(txt)];
    strcpy(new_txt, txt);

    token = strtok(new_txt, "1");
    while (token != NULL) {
        len = strlen(token);
        token = strtok(NULL, "1");
        if (len > max) {
            max = len;
        }
    }
    return max;
}

int main() {
    printf("100110100011011: %d\n", consecutive_zeros("100110100011011"));
    printf("111101111101111: %d\n", consecutive_zeros("111101111101111"));
    printf("000001100000011: %d\n", consecutive_zeros("000001100000011"));
    printf("110010101010001: %d\n", consecutive_zeros("110010101010001"));
    printf("111111111111000: %d\n", consecutive_zeros("111111111111000"));
    printf("000000000000001: %d\n", consecutive_zeros("000000000000001"));
    printf("101010101010101: %d\n", consecutive_zeros("101010101010101"));
    printf("100000000000011: %d\n", consecutive_zeros("100000000000011"));
    printf("110011110000111: %d\n", consecutive_zeros("110011110000111"));
    printf("000100000000001: %d\n", consecutive_zeros("000100000000001"));
    printf("111011011101111: %d\n", consecutive_zeros("111011011101111"));
}
