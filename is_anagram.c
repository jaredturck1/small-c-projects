// Write a function that returns true if a string is an anagram
// gcc -o is_anagram is_anagram.c

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int is_anagram(char *txt1, char *txt2) {
    int sum1 = 0;
    int sum2 = 0;
    if (strlen(txt1) != strlen(txt2)) {return false;}
    for (int i=0; i < strlen(txt1); i++) {
        sum1 += txt1[i];
        sum2 += txt2[i];
    }
    return true ? sum1 == sum2 : false;
}

int main() {
    printf("%d\n", is_anagram("typhoon", "opython"));
    printf("%d\n", is_anagram("alice", "bob"));
}
