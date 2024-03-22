#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isPalindrome(char str[], int start, int end) {
    if (start >= end)
        return true;
    if (str[start] != str[end])
        return false;
    return isPalindrome(str, start + 1, end - 1);
}
int main() {
    char str[100];
    printf("enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    if (isPalindrome(str, 0, len - 1))
        printf("it is a palindrome.\n");
    else
        printf("it is not a palindrome.\n");
    return 0;
}

