#include<iostream>
int main(){
    // character array
    char msg[5] {'H', 'e', 'l','l','o'};

    // printing the array using looping
    std::cout<<"The message is : ";
    for(auto m : msg){
        std::cout<< m ;
    }
    std::cout<<std::endl;
    // This method works, but it's not a good idea to use it like this, 
    // writing each character is not easy

    
    return 0;
}
