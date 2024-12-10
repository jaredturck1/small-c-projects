// Write a function to add thousands seperator to an integer
// gcc -o thousands_sep thousands_sep.c

#include <stdio.h>
#include <string.h>

void thousands_sep(long num) {
    char b[12];
    char output[16];
    sprintf(b, "%d", num);
    int len = strlen(b);
    int counter = 0;

    for (int i=0; i < len % 3; i++) {
        output[counter] = b[i];
        counter++;
    }
    if (counter > 0) {
        output[counter] = ',';
        counter ++;
    }

    for (int i=len % 3; i < len; i += 3) {
        output[counter] = b[i];
        output[counter + 1] = b[i + 1];
        output[counter + 2] = b[i + 2];
        output[counter + 3] = ',';
        counter += 4;
    }
    output[counter - 1] = '\0';

    printf("%d: %s\n", num, output);

}

int main() {
    thousands_sep(1234567);
    thousands_sep(1000000);
    thousands_sep(1);
    thousands_sep(251);
    thousands_sep(1117);
    thousands_sep(64007);
    thousands_sep(159237);
    thousands_sep(4859884);
    thousands_sep(24091900);
    thousands_sep(460660348);
    thousands_sep(1275629077);
}
