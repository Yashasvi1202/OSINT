#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ID_LEN 50
#define PASS_LEN 10

// Function to generate a random password
void generatePassword(char *password, int length) {
    char possibleChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    int poolSize = sizeof(possibleChars) - 1;

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % poolSize;
        password[i] = possibleChars[randomIndex];
    }
    password[length] = '\0'; // Null-terminate the string
}

int main() {
    char userId[MAX_ID_LEN];
    char password[PASS_LEN + 1];

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Accept user ID from the user
    printf("Enter User ID: ");
    if (fgets(userId, sizeof(userId), stdin) != NULL) {
        // Remove trailing newline if present
        size_t len = 0;
        while (userId[len] != '\0') {
            if (userId[len] == '\n') {
                userId[len] = '\0';
                break;
            }
            len++;
        }
    }

    // Generate random password
    generatePassword(password, PASS_LEN);

    // Display the ID and the generated password
    printf("\n--- Generated Credentials ---\n");
    printf("User ID   : %s\n", userId);
    printf("Password  : %s\n", password);

    return 0;
}
