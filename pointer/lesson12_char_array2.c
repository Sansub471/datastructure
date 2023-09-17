#include<stdio.h>
// char C[] is also interpreted as char* C
void print(const char* C){
    //C[0] = 'A'; // segmentation fault, core dumped
    // but if in the main C[20] = "Hello"; it works
    
    //C[0] = 'C';
    // if you don't want this, in the function argument const char* C

    while(*C != '\0'){
        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main(){
char C[20] = "Hello"; // string gets stored in the space for array
//char* C = "Hello"; // This is string literal
// the string gets stored as a constant in the text segment of the memory
// it can't be modified
//C[0] = 'A'; string can't be modified, segmentation fault.
print(C);
return 0;
}