#include <stdio.h>

int main(void) {
    unsigned char ch;

    printf("Enter an ASCII character: ");
    scanf("%c", &ch);

    printf("The ASCII value of %c is:\n", ch);
    printf("dec -- %d\n", ch);
    printf("hex -- %x\n", ch);

    printf("bin -- ");
    for (int i = 7; i >= 0; i--) {
        int bit = (ch >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");

    return 0;
}
