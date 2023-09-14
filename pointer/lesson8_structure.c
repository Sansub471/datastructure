#include<stdio.h>
#include<stdlib.h>

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

    return 0;
}