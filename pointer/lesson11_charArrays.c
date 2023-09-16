#include<stdio.h>
#include<string.h>

// compile with gcc -o <main> <file.c> -w

void CharPrint(char C[]){
    // compiler interprets it as char* 
    // only the base address is passed not the entire array
    int length = strlen(C);
    int size = sizeof(C); // give size of char*
    printf("The length of the string from function : %d\n", length);
    printf("The size of the string in bytes from function : %d\n", size);

    int i = 0;
    printf("The provided string is : ");
    while(C[i] != '\0'){
        printf("%c", *(C + i)); // or C[i]
        i++;
    }
    printf("\n");

    printf("The provided string print method 2 is : ");
    while(*C != '\0'){
        printf("%c", *C);
        C++;
    }
    printf("\n");
    // In second method, C++ worked eventhough at function definition 
    // C[] is used. It's because the compiler treats it as char*
    // pointer arithmetic works on char* or other pointer type

}
int main(){
    char C[6];
    C[0] = 'N';
    C[1] = 'E';
    C[2] = 'P';
    C[3] = 'A';
    C[4] = 'L';
    C[5] = '\0';
    // The string is not null terminated if C[5] is removed.
    // but here, the compiler fill the char array with null characters by default
    // hence, removing C[5] will also works
    printf("The string is : %s\n", C);

    int len = strlen(C);
    printf("The length of the string is : %d\n", len);

    // string literal
    // by default the string is end by a null character
    char str[] = "Nepal is my country.";
    printf("The sentence is : %s\n", str);
    int length = strlen(str);
    printf("Length of sentence : %d\n", length);

    // Another way of initialization
    char country[6] = {'N', 'E', 'P', 'A', 'L', '\0'};
    // end character must be explicit
    printf("Country name : %s\n", country);

    // arrays and pointers are different types that are used in similar manner
    char C1[6] = "Hello"; 
    char* C2;
    C2 = C1;
    printf("C2[1] = %c\n", C2[1]);  
    C2[0] = 'A';
    printf("C2 = %s\n", C2);

    int lenc2 = strlen(C2);
    // The characters of C2 are : 
    printf("The characters of C2 are : ");
    for(int i=0; i<lenc2; i++){
        printf("%c", C2[i]); // C2[i] is *(C2 + i)
    }
    printf("\n");

    printf("The characters of C2 are : ");
    for(int i=0; i<lenc2; i++){
        printf("%c", *(C2 + i)); // C2[i] is *(C2 + i)
    }
    printf("\n");

    printf("The characters of C2 are : ");
    for(int i=0; i<lenc2; i++){
        printf("%c", *C2); // C2[i] is *(C2 + i)
        C2++;
    }
    printf("\n\n");

    printf("The characters of C1 are : ");
    for(int i=0; i<lenc2; i++){
        printf("%c", *(C1 + i)); // C1[i] is *(C1 + i)
    }
    printf("\n");

    printf("The characters of C1 are : ");
    for(int i=0; i<lenc2; i++){
        printf("%c", C1[i]); // C1[i] is *(C1 + i)
    }
    printf("\n");

    // But, C1  is not equal to C2; C1 = C2; error
    printf("The characters of C1 are : ");
    for(int i=0; i<lenc2; i++){
        printf("%c", *C1); // points to the first char, C1[0]
        //C1++; error
    }
    printf("\n\n");

    // Arrays are always passed by reference to functions
    char nationality[] = "Nepali";
    int lengthStr = strlen(nationality);
    int size = sizeof(nationality);
    printf("The length of the string from main : %d\n", lengthStr);
    printf("The size of the string in bytes from main : %d\n", size);
    printf("\n");

    CharPrint(nationality);
    return 0;
}