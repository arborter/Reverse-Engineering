#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char try[10];  
char password[] = "pass";
char input[10];
int attempts = 3;

int main() {
    //printf("Please enter your password:\n");
    
    // Use fgets to read password, but remove the newline
    //fgets(try, sizeof(try), stdin);
    //try[strcspn(try, "\n")] = 0;  // Remove the newline character

    while(attempts > 0){
        printf("Welcome. Please enter your password:\n");
        
        // Get user input and remove newline
        fgets(try, sizeof(try), stdin);
        try[strcspn(try, "\n")] = 0;  // Remove the newline character
        
        if (strcmp(try, password) == 0) {
            printf("Access granted.\n");
            FILE *file = fopen("mytext.txt", "r+");
            if (file == NULL) {
                printf("No file found.\n");
            } else {
                printf("Would you like to Read or Write to a file? r or w\n");
                fgets(input, sizeof(input), stdin);
                
                char buffer[100];
                if (input[0] == 'r') {
                    while (fgets(buffer, sizeof(buffer), file)) {
                        printf("%s", buffer);
                    }
                } else if (input[0] == 'w') {
                    printf("Type your desired input\n");
                    fgets(buffer, sizeof(buffer), stdin);  // capture input
                    fprintf(file, "%s", buffer);  // saved input
                } else {
                    printf("Not a valid input\n");
                }
                fclose(file);
            }
            break;  // Exit the loop after successful access
        } else {
            attempts--;
            printf("Access denied. Tries remaining: %i\n", attempts);
        }
    }
    if (attempts == 0) {
        printf("You have been locked out due to too many failed attempts.\n");
    }
    return 0;
}