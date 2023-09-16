#include<stdio.h>
#include<string.h>

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


    return 0;
}