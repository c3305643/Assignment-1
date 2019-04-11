#include <stdio.h>

int main() {
    
    int x;
    
    printf("CHOOSE DESIRED OPTION:\n");
    printf("1. Encrypt a message with a rotation cipher given the message and rotation amount\n");
    printf("2. Decrypt a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("3. Encrypt a message with a substitution cipher given message text and alphabet substitution\n");
    printf("4. Decrypt a message encrypted with a substitution cipher given cipher text and substitutions\n");
    printf("5. Decrypt a message encrypted with a rotation cipher given cipher text only\n");
    printf("6. Decrypt a message encrypted with a substitution cipher given cipher text only\n");
    scanf("%d", &x);
    
    
    switch(x){
        case 1:         // encryption of a message with a rotation cipher given message and rotation amount
            FILE *input;
            input = fopen("decryptedMessage", "r");
            
            break;
            
        case 2:         // Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
            printf("2\n");
            break;
            
        case 3:         // Encryption of a message with a substitution cipher given message text and alphabet substitution
            printf("3\n");
            break;
            
        case 4:         // Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
            printf("4\n");
            break;
            
        case 5:         // Decryption of a message encrypted with a rotation cipher given cipher text only
            printf("5\n");
            break;
            
        case 6:         // Decryption of a message encrypted with a substitution cipher given cipher text only
            printf("6\n");
            break;
        default: 
            printf("no option was selected\n");
    }
    return 0;
}