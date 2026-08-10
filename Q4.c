#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], clean[100];
    int i, j = 0, len, flag = 1;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ')
            clean[j++] = tolower(str[i]);
    }

    clean[j] = '\0';
    len = strlen(clean);

    for (i = 0; i < len / 2; i++) {
        if (clean[i] != clean[len - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;
}
