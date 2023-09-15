#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100
struct Student{
    char* name;
    int age;
    float GPA;
};

struct Student* newStudent(char* name, int age, float GPA){
    struct Student* s = (struct Student*)malloc(sizeof(struct Student));
    s->name = name; // (*s).name = name;
    s->age = age;
    s->GPA = GPA;
    return s;
}

void Print(struct Student* s){
    printf("The student's profile : \n");
    printf("Name : %s\n", s->name);
    printf("Age  : %d\n", (*s).age); // s->age
    printf("GPA  : %.2f\n", s->GPA);
    printf("\n");
}
int main(){
    struct Student* s = (struct Student*)malloc(sizeof(struct Student));
    s->name = "Subash Mainali";
    s->age = 24;
    s->GPA = 3.78;
    Print(s);

    char* cricketPlayer = "Kushal Bhurtel";
    struct Student* std = newStudent(cricketPlayer, 26, 3.89);
    Print(std);

    return 0;
}