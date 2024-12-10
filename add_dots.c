// write a function that adds/removes dots from a string
// gcc -o add_dots add_dots.c

#include <stdio.h>
#include <string.h>

char* add_dots(char *txt, char *new_str) {
    int i;
    for (i=0; i < strlen(txt); i++) {
        new_str[i*2] = txt[i];
        new_str[(i*2)+1] = '.';
    }
    new_str[2*i-1] = '\0';
    return new_str;
}

char* remove_dots(char *txt, char *new_str) {
    int olen = strlen(new_str);
    int i;
    for (i=0; i < strlen(txt); i += 2) {
        new_str[i/2] = txt[i];
    }
    for (i = (strlen(txt)/2)+1; i < olen; i++) {
        new_str[i] = '\0';
    }
    return new_str;
}

int main() {
    char input_txt[100];
    printf("Enter text: ");
    scanf("%s", input_txt);
    char new_str[strlen(input_txt) * 2];
    printf("%s\n", add_dots(input_txt, new_str));
    printf("%s\n", remove_dots(add_dots(input_txt, new_str), new_str));
}
