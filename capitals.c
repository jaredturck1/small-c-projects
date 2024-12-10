// Given a string, print out all captial letters within the string
// gcc -o capitals capitals.c

#include <string.h>
#include <stdio.h>

int capitals(char* txt) {
    char array[strlen(txt)];
    int counter = 0;

    for (int i=0; i < strlen(txt); i++) {
        if (txt[i] >= 65 && txt[i] <= 90) {
            array[counter] = txt[i];
            counter++;
        }
    }
    printf("%s\n", array);
}

int main() {
    char input_txt[100];
    printf("Enter text: ");
    fgets(input_txt, 100, stdin);
    capitals(input_txt);
}
