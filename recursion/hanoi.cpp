#include<iostream>
#define A 1
#define B 2
#define C 3

void TowerHanoi(int n, int start, int end){

}
int main(){
    int n, start, end;
    std::cout<<"The number of pucks : n "; std::cin>>n;
    std::cout<<"The starting tower : (1-3)"; std::cin>>start;
    std::cout<<"The target  tower  : (1-3)"; std::cin>>end;

    if(n < 0 || start <= 0 || start > 3 || end <= 0 || end > 3 || start == end){
        std::cout<<"Make sure the inputs are valid!"<<std::endl;
        return -1;
    }


    return 0;
}