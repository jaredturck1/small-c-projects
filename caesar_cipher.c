// implement the Caesar cipher
// gcc -o caesar_cipher caesar_cipher.c

#include <stdio.h>

void caesar_cipher(char *txt, int key, int txt_len) {
    char cipher[txt_len];
    for (int i=0; i < txt_len; i++) {
        cipher[i] = ((txt[i] - 97 + key) % 26) + 97;
    }
    printf("%s --> %s\n", txt, cipher);
}

int main() {
    caesar_cipher("hello", 2, 5);
    caesar_cipher("jgnnq", -2, 5);
}
