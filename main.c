#include <stdio.h>

int rcipherE();     // encryption of a message with a rotation cipher given message and rotation amount

int rcipherD();     // Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount

int scipherE();     // Encryption of a message with a substitution cipher given message text and alphabet substitution

int scipherD();     // Decryption of a message encrypted with a substitution cipher given cipher text and substitutions

int rcipherDto();   // Decryption of a message encrypted with a rotation cipher given cipher text only

int scipherDto();   // Decryption of a message encrypted with a substitution cipher given cipher text only

    
int main() {
    
    int x = 1, k = 1;   // x is used as a selection variable for the menu, k is the rotation amount
    
    // ******use the terminal to input a value for x and k or change the value in the code******
    // message tells user to place the required message in the correct file for encryption of decryption
    printf("...before continuing, make sure the message you want to encrypt is in decryptedMessage.txt,\n or alternatively if you want to decrpyt a message, place it in encryptedMessage.txt\n");
    printf("\n");
    printf("CHOOSE DESIRED OPTION:\n");     // prints user menu to the terminal
    printf("1. Encrypt a message with a rotation cipher given the message and rotation amount\n");
    printf("2. Decrypt a message encrypted with a rotation cipher given cipher text and rotation amount\n");
    printf("3. Encrypt a message with a substitution cipher given message text and alphabet substitution\n");
    printf("4. Decrypt a message encrypted with a substitution cipher given cipher text and substitutions\n");
    printf("5. Decrypt a message encrypted with a rotation cipher given cipher text only\n");
    printf("6. Decrypt a message encrypted with a substitution cipher given cipher text only\n");
    scanf("%d", &x);        // reads users menu choice
    
    if (x == 2 || x == 1){  // if x is 1 or 2, the terminal will ask for rotation amount for the rotation cipher
        printf("rotation amount for rotation cipher: ");
        scanf("%d", &k);
        printf("%d\n", k);  // show user the rotation amount
    }
    else if (x == 4 || x == 3){   // if x is 3 or 4, the terminal will ask to place the substitution key into the file "subKey.txt"
        printf("Write subsitution key into subKey.txt file in the form ABCDEFGHILKLMNOPQRSTUVWXYZ\n");
    }
    
    
    switch(x){
        case 1:             // encryption of a message with a rotation cipher given message and rotation amount
            
            rcipherE(k);
            
            
            break;
            
        case 2:             // Decryption of a message encrypted with a rotation cipher given cipher text and rotation amount
            
            rcipherD(k);
            
            break;
            
        case 3:             // Encryption of a message with a substitution cipher given message text and alphabet substitution
            
            scipherE();
            
            break;
            
        case 4:             // Decryption of a message encrypted with a substitution cipher given cipher text and substitutions
            
            scipherD();
            
            break;
            
        case 5:             // Decryption of a message encrypted with a rotation cipher given cipher text only
            
            rcipherDto();
            
            break;
            
        case 6:             // Decryption of a message encrypted with a substitution cipher given cipher text only
            
            scipherDto();
            
            break;
        default: 
            printf("no option was selected\n");        // if x does not = 1 to 6 then the terminal will tell the user that no option was selected
    }
    return 0;
}

int rcipherE(int k){
    
    FILE *size;         // to initially find the size the array needs to be
	                    // store decrypted message in "decryptedMessage.txt" for encrypting
	size = fopen("decryptedMessage.txt", "r");

	int x = 0;         // count variable
	char c;            // varible for scanning character in loop
	
	while (feof(size) == 0){    
	    
    	fscanf(size, "%c", &c);    // scan character from file 
        
	    x++;           // loop cycles through the file counting each character in the file
	}
	
	fclose(size);      // close file

    FILE *input;       // open file to place contents into a string
    
	input = fopen("decryptedMessage.txt", "r");     // open file
	
    char str[x];                    // array for string 
    int s = x-1;                    // variable for the last character in the. x - 1 is used so the NULL character isnt considered 
    x = 0;
    
    printf("Input Message: ");             //print users input message from file
    
    for (x = 0; x < s; x++){               // loop for changing lower case to upper case
	    
	    
    	fscanf(input, "%c", &c);           // scan from file and write to c
    	printf("%c", c);                   // print character to terminal which will in the end print the full message
    	
    	
    	str[x] = c;                        // place c into the x position of the string
    	
    	if(str[x] > 96 && str[x] < 123){   // if the character is lower case i.e. ascii value between 97 and 122
            
    	    str[x] = str[x] - 32;          // make the character upper case by minusing the ascii value by 32
                          
    	}
        	   
	}
	
	fclose(input);                         // close file
	
	printf("\n");                          // new line                       
	
	FILE *output;                          // file for writing 
	output = fopen("encryptedMessage.txt", "w");   // open file for writing
	
	printf("Encrpyted Message: ");         // terminal prints the encrypted message
	
	for (x = 0; x < s; x++){               // loop for string
	    
	    
	    
	    if (str[x] > 64 && str[x] < 91){   // only includes letters
	        
	        if (str[x] + k < 91){          // if rotation + character doesnt go past z
	        
	            str[x] = str[x] + k;       // character = character - rotation
	        }
	        
	        else if(str[x] + k > 90){      // if rotation + character does go past z, use remainer + 52 to bring it back into the A - Z range
	           
	           str[x] = ((str[x] + k) % 26) + 52;  // remainder of character + rotation + 52
	           
	        }	        
	        
	    }
	    
	    fprintf(output, "%c", str[x]);     // print encrypted character to file
	    printf("%c", str[x]);              // print encrypted character to terminal
	}
	
	fclose(output);                        // close file
	
    return 0;     
}

int rcipherD(int k){   
    
    FILE *size;                            // to initially find the size the array needs to be
	                                       // store decrypted message in "decryptedMessage.txt" for encrypting
	size = fopen("encryptedMessage.txt", "r");     // open file

	int x = 0;                             // count variable
	char c;                                // character variable
	
	while (feof(size) == 0){               // loop for finding size of file
	    
    	fscanf(size, "%c", &c);            // scan character from file to 'c'
        
	    x++;                               // count
	}
	
	fclose(size);                          // close file

    FILE *input;                           // write the file to an array
    
	input = fopen("encryptedMessage.txt", "r");    // open file
	
    char str[x];                           // array for string
    int s = x-1;                           // last character for loop
    x = 0;
    
    printf("Input Message: ");
    
    for (x = 0; x < s; x++){               // loop for writing file to a string
	    
	    
    	fscanf(input, "%c", &c);           // scan file character to c
        str[x] = c;                        // declare x position character in string to be c
        printf("%c", str[x]);              // print input character to terminal to show input message
              
	}
	
	fclose(input);                         // close         
	
	printf("\n");
	
	FILE *output;                          // open file for output
	output = fopen("decryptedMessage.txt", "w");   // open file
	
	printf("Decrypted Message: ");
	
	for (x = 0; x < s; x++){               // loop for decrypting text
	    
	    
	    
	    if (str[x] > 64 && str[x] < 91){   // ignore unless character is A - Z
	        
	        if (str[x] - k > 64){          // if character - rotation >= 'A'
                str[x] = str[x] - k;       // decrypted character = encrypted character - rotation
                
            }
            else if(x - k < 65){           // if character - rotation is < 'A', use remained and addition to bring it back into A-Z range
                str[x] = ((str[x] - k) % 26) + 78;  //decrypted character = remainder of encrypted character - rotation + 78              
            } 
            
	    }
	    
	    fprintf(output, "%c", str[x]);	   // printf decrypted character to file
	    printf("%c", str[x]);              // printt decrypted character to tre
	}
	
	fclose(output);                        // close file
    
    return 0;
}

int scipherE(){                             
    
    FILE *key;                              // open file for key
    key = fopen("subKey.txt", "r");         // open file subKey.txt
    
    int x = 0;                              // count variable
    char str[26];                           // string for key
    char c;                                 // variable for character
    
    printf("the key is: ");                 // printf key to terminal
    for (x = 0; x < 26; x++){               // loop for reading key
        
        fscanf(key, "%c", &c);              // scan key character to c
        str[x] = c;                         // place c into x position in string
        printf("%c", str[x]);               // print c to terminal
    }
    
    fclose(key);                            // close file
    
    FILE *size;                            // to initially find the size the array needs to be
                    	                   // store decrypted message in "decryptedMessage.txt" for encrypting
	size = fopen("decryptedMessage.txt", "r"); // open file for reading size
	
	x = 0;                                 // count initally = 0
	
	while (feof(size) == 0){               // loop for file size
	    
    	fscanf(size, "%c", &c);            // scan file character to c
        
	    x++;                               // count x + 1
	}
	   
	fclose(size);                          // close file

    FILE *input;        // write the file to an array
    
	input = fopen("decryptedMessage.txt", "r");    // open file for input
	
    char str2[x];                           // second string for input file
    int s = x-1;                            // s is the last character in string
    x = 0;
    printf("\n");
    printf("Input Message: ");              // input message to terminal
    
    for (x = 0; x < s; x++){                // loop forn printing file to array
	    
	    
    	fscanf(input, "%c", &c);           // scan file character to c
    	
    	str2[x] = c;                       // position x in string = c
    	
    	if(str2[x] > 96 && str2[x] < 123){ // if character is lower case
            
    	    str2[x] = c - 32;              // ASCII value - 32 will make it upper case
                        
    	}
    	
        printf("%c", str2[x]);             // prints message to terminal
	}
	
	fclose(input);                         // close file
	
	int a, b;                              // variable for encryption technique
	
	printf("\n");                          // new line in terminal
	
	FILE *output;                          // open file for printing output    
	output = fopen("encryptedMessage.txt", "w");   // open file
	
	printf("Encrypted Message: ");         // prints encrypted message to terminal
	
	for (x = 0; x < s; x++){               // loop for encryption
	    
	    for(b = 0; b < 26; b++){           // for the range of the alphabet
	        
	        a = b + 65;                    // + 65 gets it in the A - Z range
	        
	        if (str2[x] == a){             // if input message character = b + 65
	            str2[x] = str[b];          // then sub the b position character into the original string
	            break;                     // break loop
	        }	        
	    }
	    	    
	    printf("%c", str2[x]);             // prints encrypted message to terminal
	    fprintf(output, "%c", str2[x]);    // prints encrypted message to file
	}
	
	fclose(output);                        // close file
    
    
    return 0;
}

int scipherD(){
    
    FILE *key;                             // open file for reading key
    key = fopen("subKey.txt", "r");        // open file
    
    int x = 0;                             // count variable
    char str[26];                          // string for key    
    char c;                                // variable for scanning from file    
    
    printf("the key is: ");                // print key to terminal
    
    for (x = 0; x < 26; x++){              // loop for scanning key
        
        fscanf(key, "%c", &c);             // scan key to c
        str[x] = c;                        // let c = position x of string 
        printf("%c", str[x]);              // print key to terminal
        
    }
    
    fclose(key);                           // close file
    
    FILE *size;                            // to initially find the size the array needs to be
	                                       // store decrypted message in "decryptedMessage.txt" for encrypting
	size = fopen("encryptedMessage.txt", "r"); //open file
	
	while (feof(size) == 0){               // loop for file size
	    
    	fscanf(size, "%c", &c);            // scan file character to c
        
	    x++;                               // count
	}
	
	fclose(size);                          // file close

    FILE *input;                           // write the file to an array
    
	input = fopen("encryptedMessage.txt", "r");    // file open
	
    char str2[x];                          // second string for input
    int s = x-1;                           // last character in array
    
    printf("\n");                          // new line
    printf("Input Message: ");             // print input message to terminal
    
    for (x = 0; x < s; x++){               // loop for putting file into string
	    
	    
    	fscanf(input, "%c", &c);           // scan file character to c
    	       
    	str2[x] = c;                       // let c = position x in string

        printf("%c", str2[x]);             // print input message to terminal

	}
	
	fclose(input);                         // file close
	
	int b;                                 // variable for decryption technique
	
	printf("\n");                          // new line
	
	FILE *output;                          // open file for output decrypted message
	output = fopen("decryptedMessage.txt", "w");   // file open
	
	printf("Decrypted Message: ");         // print decrypted message to terminal
	
	for (x = 0; x < s; x++){               // loop for printing decryption
	    
	    for(b = 0; b < 26; b++){           // range of alphabet
	        
	        if (str[b] == str2[x]){        // if position b key character equals string character
	            str2[x] = b + 65;          // then string character = b + 65
	            break;                     // break loop
	        }	        
	    }
	    
	    
	    printf("%c", str2[x]);             // print decryption to terminal
	    fprintf(output, "%c", str2[x]);    // print decryption to file
	}
	
	fclose(output);                        // close file
    
    
    
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
