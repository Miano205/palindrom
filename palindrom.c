#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove spaces and convert to lowercase
void preprocessString(char str[], char processedStr[]) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            processedStr[j++] = tolower(str[i]);
        }
    }
    processedStr[j] = '\0';
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // It's a palindrome
}

int main() {
    char str[100], processedStr[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline character
    str[strcspn(str, "\n")] = '\0';

    preprocessString(str, processedStr);

    if (isPalindrome(processedStr)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}
