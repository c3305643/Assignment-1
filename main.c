#include <stdio.h>

int rcipherE();     // encryption of a message with a rotation cipher given message and rotation amount

int rcipherD();     // Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount

int scipherE();     // Encryption of a message with a substitution cipher given message text and alphabet substitution

int scipherD();     // Decryption of a message encrypted with a substitution cipher given cipher text and substitutions

int rcipherDto();   // Decryption of a message encrypted with a rotation cipher given cipher text only

int scipherDto();   // Decryption of a message encrypted with a substitution cipher given cipher text only

    
int main() {
    
    
    
    printf("CHOOSE DESIRED OPTION:\n");
    printf("1. Encrypt a message with a rotation cipher given the message and rotation amount\n");
    printf("2. Decrypt a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("3. Encrypt a message with a substitution cipher given message text and alphabet substitution\n");
    printf("4. Decrypt a message encrypted with a substitution cipher given cipher text and substitutions\n");
    printf("5. Decrypt a message encrypted with a rotation cipher given cipher text only\n");
    printf("6. Decrypt a message encrypted with a substitution cipher given cipher text only\n");
    
    
    const int x = 1;
    
    switch(x){
        case 1:         // encryption of a message with a rotation cipher given message and rotation amount
        
            rcipherE();
            
            break;
            
        case 2:         // Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
            
            rcipherD();
            
            break;
            
        case 3:         // Encryption of a message with a substitution cipher given message text and alphabet substitution
            
            scipherE();
            
            break;
            
        case 4:         // Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
            
            scipherD();
            
            break;
            
        case 5:         // Decryption of a message encrypted with a rotation cipher given cipher text only
            
            rcipherDto();
            
            break;
            
        case 6:         // Decryption of a message encrypted with a substitution cipher given cipher text only
            
            scipherDto();
            
            break;
        default: 
            printf("no option was selected\n");
    }
    return 0;
}

int rcipherE(){
    
    int a = 0;
    
    FILE *input;
    input =  fopen("decryptedMessage.txt", "r");
    
    while (feof(input) == 0){
        
    a++;     
    
    }
    printf("%d", a);
    
    return 0;
}

int rcipherD(){
    
    
    return 0;
}

int scipherE(){
    
    
    return 0;
}

int scipherD(){
    
    
    return 0;
}

int rcipherDto(){
    
    
    return 0;
}

int scipherDto(){
    
    
    return 0;
}
