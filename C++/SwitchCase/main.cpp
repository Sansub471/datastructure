#include<iostream>

const int sharpner{20};
const int eraser{30};
const int pencil{40};

int main(){

int tool {pencil};

switch (tool) {
    case  sharpner:
    {
        std::cout<<"Sharpen your pencil."<<std::endl;
    }
    break;
    case eraser:
    {
        std::cout<<"Correct your mistake."<<std::endl;
    }
    break;
    case pencil:
    {
        std::cout<<"Keep writing."<<std::endl;
    }
    break;
    default :
    {
        std::cout<<"Today is reading time."<<std::endl;
    }
}
    
return 0;
}

// switch case must ba integral or enum type
// not a string or float type

// Revision of switch case done.