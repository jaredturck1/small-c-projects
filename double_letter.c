// given a string return true if the same letter appears twice in a row
// gcc -o double_letter double_letter.c

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int double_letter(char *txt) {
    for (int i=0; i < strlen(txt) - 1; i++) {
        if (txt[i] == txt[i+1]) {
            return true;
        }
    }
    return false;
}

int main() {
    char input_txt[100];
    printf("Enter text: ");
    scanf("%s", input_txt);
    printf("%d\n", double_letter(input_txt));
}
