// Write a function that returns the middle letter of a given string
// gcc -o middle_letter middle_letter.c

#include <string.h>
#include <stdio.h>

char middle(char* txt) {
    int mid = strlen(txt) / 2;
    if (strlen(txt) % 2 != 0) {
        return txt[mid];
    } else {
        return '\0';
    }
}

int main() {
    char input_txt[100];
    printf("Enter string: ");
    scanf("%s", input_txt);
    printf("%c\n", middle(input_txt));
}
