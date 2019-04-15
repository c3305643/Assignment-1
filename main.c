#include <stdio.h>

int rcipherE();     // encryption of a message with a rotation cipher given message and rotation amount

int rcipherD();     // Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount

int scipherE();     // Encryption of a message with a substitution cipher given message text and alphabet substitution

int scipherD();     // Decryption of a message encrypted with a substitution cipher given cipher text and substitutions

int rcipherDto();   // Decryption of a message encrypted with a rotation cipher given cipher text only

int scipherDto();   // Decryption of a message encrypted with a substitution cipher given cipher text only

    
int main() {
    
    int x = 1, k = 5;
    
    // use the terminal to input a value for x and k or change the value in the code
    
    printf("CHOOSE DESIRED OPTION:\n");
    printf("1. Encrypt a message with a rotation cipher given the message and rotation amount\n");
    printf("2. Decrypt a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("3. Encrypt a message with a substitution cipher given message text and alphabet substitution\n");
    printf("4. Decrypt a message encrypted with a substitution cipher given cipher text and substitutions\n");
    printf("5. Decrypt a message encrypted with a rotation cipher given cipher text only\n");
    printf("6. Decrypt a message encrypted with a substitution cipher given cipher text only\n");
    scanf("%d", &x);
    
    printf("rotation amount for rotation cipher: \n");
    scanf("%d", &k);
    
    switch(x){
        case 1:         // encryption of a message with a rotation cipher given message and rotation amount
            
            rcipherE(k);
            
            
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

int rcipherE(int k){
    
    FILE *size;        // to initially find the size the array needs to be
	                   // store decrypted message in "decryptedMessage.txt" for encrypting
	size = fopen("decryptedMessage.txt", "r");

	int x = 0;
	char c;
	
	while (feof(size) == 0){    
	    
    	fscanf(size, "%c", &c);
        
	    x++;
	}
	
	fclose(size);

    FILE *input;        // write the file to an array
    
	input = fopen("decryptedMessage.txt", "r");
	
    char str[x];
    int s = x-1;
    x = 0;
    
    while (feof(input) == 0){
	    
	    
    	fscanf(input, "%c", &c);
    	
    	str[x] = c;
    	
    	if(str[x] > 96 && str[x] < 123){
            
    	    str[x] = c - 32;
            str[s] = '\0';
              
    	}
        
	    x++;
	}
	
	fclose(input);
	
	x = 0;
	
	FILE *output;
	output = fopen("encryptedMessage.txt", "w");   
	
	for (x = 0; x < s; x++){
	    
	    
	    
	    if (str[x] > 64 && str[x] < 91){
	        
	        if (str[x] + k < 91){
	            
	            str[x] = str[x] + k;
	        }
	        else if(str[x] + k > 90){
	           
	           str[x] = ((str[x] + k) % 26) + 52;
	           
	        }
	        
	        
	    }
	    
	    fprintf(output, "%c", str[x]);
	    
	}
	
	fclose(output);
	
    return 0; 
    
}

int rcipherD(){
    
    printf("yess");
    
    return 0;
}

int scipherE(){
    
    printf("yis");
    
    return 0;
}

int scipherD(){
    
    printf("neg");
    
    
    return 0;
}

int rcipherDto(){
    
    printf("hanoi");
    
    
    return 0;
}

int scipherDto(){
    
    printf("no");
    
    return 0;
}
