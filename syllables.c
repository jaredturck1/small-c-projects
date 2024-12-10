// Write a function that counts the number of syllables in a string
// gcc -o syllables syllables.c

#include <stdio.h>
#include <string.h>

int syllables(char *txt) {
    int count = 0;
    for (int i=0; i < strlen(txt); i++) {
        if (txt[i] == 45) {
            count++;
        }
    }
    return count + 1;
}

int main() {
    printf("%d: hotel\n", syllables("ho-tell"));
    printf("%d: cat\n", syllables("cat"));
    printf("%d: mataphor\n", syllables("met-a-phor"));
    printf("%d: terminator\n", syllables("ter-min-a-tor"));
}
