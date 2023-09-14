#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
struct Student{
    char* name;
    int age;
    float GPA;
};

int main(){
    struct Student* s = (struct Student*)malloc(sizeof(struct Student));
    s->name = "Subash Mainali";
    s->age = 24;
    s->GPA = 3.78;

    printf("The student's profile : \n");
    printf("Name : %s\n", s->name);
    printf("Age  : %d\n", (*s).age); // s->age
    printf("GPA  : %.2f\n", s->GPA);

    // string revision
    char name[100] = "The name of my school is IOE.";
    printf("The school is : %s \n", name);

    char* school = "The school name is IOE.";
    printf("The school : %s\n", school);
    printf("The school : %c\n", school[19]);
    
    // looping over string using char*
    printf("School name by looping : ");
    while(*school != '\0'){
        printf("%c", *school);
        school++;
    }
    printf("\n");

    // dynamic string memory allocation
    char* dynamic_name = (char*)malloc(MAX_SIZE * sizeof(char));
    printf("Enter a string : ");
    scanf("%s", dynamic_name);

    printf("The entered string is : %s\n", dynamic_name);
    return 0;
}