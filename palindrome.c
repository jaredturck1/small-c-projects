// Write a function that returns true if a string is a palindrome
// gcc -o palindrome palindrome.c

#include <string.h>
#include <stdio.h>

int palindrome(char *txt) {
    int sum1 = 0;
    int sum2 = 0;
    int str_len = strlen(txt);

    for (int i=0; i < str_len; i++) {
        sum1 += txt[i] * (i+1);
        sum2 += txt[str_len - i - 1] * (i+1);
    }
    return sum1 == sum2;
}

int main() {
    printf("bob: %d\n", palindrome("bob"));
    printf("abba: %d\n", palindrome("abba"));
    printf("abcd: %d\n", palindrome("abcd"));
    printf("level: %d\n", palindrome("level"));
    printf("racecar: %d\n", palindrome("racecar"));
}
