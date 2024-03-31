#include<stdio.h>
#include<stdlib.h>

struct Student{
    char* name;
    int age;
    char* level;
    float GPA;

};

void PrintStudent(struct Student s){
    printf("-------------------Student's Profile------------\n");
    printf("Name : %s\n", s.name);
    printf("Age : %d\n", s.age);
    printf("Level : %s\n", s.level);
    printf("GPA : %.2f\n", s.GPA);
    printf("--------------------------------------------------\n");
}
int main(){
    struct Student st;
    st.name = "Kushal Bhurtel";
    st.age = 28;
    st.level = "BE";
    st.GPA = 3.89;

    PrintStudent(st);

    return 0;
}