#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    printf("------------------------------------------------\n");
}

void PrintStudentPtr(struct Student* s){
    printf("-------------------Student's Profile------------\n");
    printf("Name : %s\n", (*s).name);
    printf("Age : %d\n", (*s).age);
    printf("Level : %s\n", (*s).level);
    printf("GPA : %.2f\n", (*s).GPA);
    printf("------------------------------------------------\n");
}
struct Student* newStudent(char* name, int age, char* level, float GPA){
    struct Student* stdnt = (struct Student*)malloc(sizeof(struct Student));
    if(stdnt == NULL){
        return NULL; // Memory allocation has failed.
    }
    stdnt->name = name;
    (*stdnt).age = age; 
    stdnt->level = level;
    stdnt->GPA = GPA;

    // char* arguments passed are not copied here, simply pointer assigned.
    // The life time of char* type arguments passed must be longer than the structure 


    // return &stdnt is not allowed, because it is the address of the pointer, not the address pointed by it
    // Also, it would mean we are trying to return the address of the local variable 'stdnt'
    // And, the return type for it would be struct** where in our functin it's struct*
    return stdnt;
}

struct Student* newStudentImproved(const char* name, int age, const char* level, float GPA) {
    // Allocate memory for the Student structure
    struct Student* stdnt = (struct Student*)malloc(sizeof(struct Student));
    if (stdnt == NULL) {
        return NULL; // Memory allocation has failed
    }
    
    // Allocate memory for the name and level strings and copy the provided strings
    stdnt->name = strdup(name);
    if (stdnt->name == NULL) {
        free(stdnt); // Free the allocated memory for the Student structure
        return NULL; // Memory allocation has failed
    }

    stdnt->level = strdup(level);
    if (stdnt->level == NULL) {
        free(stdnt->name); // Free the allocated memory for the name string
        free(stdnt);      // Free the allocated memory for the Student structure
        return NULL;      // Memory allocation has failed
    }

    // Initialize other fields of the Student structure
    stdnt->age = age;
    stdnt->GPA = GPA;

    return stdnt;
}

// Let's try something, can we return struct like this:
struct Student newStudant(char* name, int age, char* level, float GPA){
    struct Student stdn;
    stdn.name = name; // better to allocate memory and copy first for pointer type 
    stdn.age = age;
    stdn.level = level;
    stdn.GPA = GPA;
    return stdn;
}

int main(){
    struct Student st;
    st.name = "Kushal Bhurtel";
    st.age = 28;
    st.level = "BE";
    st.GPA = 3.89;

    PrintStudent(st);

    // Structure with dynamic allocation
    char* name = "Rohit Poudel";
    char* level = "BSC";
    int age = 22;
    float GPA = 3.90;

    struct Student* stdnt = newStudent(name, age, level, GPA);
    PrintStudentPtr(stdnt);   

    // Where is the confusion?
    // Well, PrintStudentPtr() function can take Student* as argument.
    // We can pass, &s but not the address of stdnt. Why?
    // Because, the &stdnt can be stored only in Student** type, and the function can only take Student*

    // What will happend if we free the passed char* arguments to the function newStudent()
    //free(name);
    //free(level);
    //PrintStudentPtr(stdnt);

    // Try with newStudentImproved() function
    struct Student* stde = newStudentImproved(name, age, level, GPA);
    PrintStudentPtr(stde);

    //struct Student est = newStudant(name, age, level, GPA);
    //PrintStudent(est);
    return 0;
}