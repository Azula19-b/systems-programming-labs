/*
Name: Bahar Ozer
*/


#include <stdio.h>

int main(void) {
    unsigned char ch;   
    int i;
    int bit;

    printf("Enter an ASCII character: ");
    scanf(" %c", &ch);

    printf("The ASCII value of %c is:\n", ch);
    printf("dec -- %d hex -- %x bin -- ", ch, ch);

    for (i = 7; i >= 0; i--) {
        bit = ch >> i;
        if (bit & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\n");
    return 0;
}
