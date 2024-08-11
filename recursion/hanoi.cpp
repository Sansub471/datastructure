#include<iostream>
#define A 1 // source
#define B 2 // auxiliary
#define C 3 // destination

int stepsCounter;

void printMove(int start, int end){
    std::cout<<"Move from " << start << " ---> " << end << std::endl;
    stepsCounter++;
}

// youtube.com/Abdul Bari
// TOH(n, A, B, C){
//   if n<= 0 return
//   TOH(n-1, A, C, B)
//   print Move from A to C
//   TOH(n-1, B, A, C)
//}
void TowerHanoi(int n, int src, int aux, int dest){
    if (n <= 0){
        return;
    }
    TowerHanoi(n-1, src,  dest , aux ); // move n-1 from 'src' to 'aux' using 'dest' 
    printMove(src, dest);// move from 'src' to 'dest'
    TowerHanoi(n-1, aux, src, dest); // move n-1 from 'aux' to 'dest' using 'src'
}

// youtube.com/Reducible
// if n<= 0 return
void hanoiTower(int n, int start, int end){
    if(n<=0) return;
    if (n == 1){
        printMove(start, end);
    }
    else{
        int other = 6 - (start + end);
        hanoiTower(n - 1, start, other);
        printMove(start, end);
        hanoiTower(n - 1, other, end);
    }
}

int main(){
    int n, start, end;
    std::cout<<"The number of pucks (discs) n : "; std::cin>>n;
    // std::cout<<"The starting     tower  (1-3) : "; std::cin>>start;
    // std::cout<<"The destination  tower  (1-3) : "; std::cin>>end;

    // if(n <= 0 || start <= 0 || start > 3 || end <= 0 || end > 3 || start == end){
    //     std::cout<<"Make sure the inputs are valid!"<<std::endl;
    //     return -1;
    // }
    // the start and end towers are asked to give user control over the location of disks
    // it doesn't make difference in solving the problem at all
    // hence by default let's keep start = A, end = C and aux = C

    start = A; end = C;
    int aux = 6 - (start + end); // or aux = B

    std::cout<<"\nImplementation I  : \n" << std::endl;
    stepsCounter = 0;
    TowerHanoi(n, start, aux, end);
    std::cout<<"Total Moves = " << stepsCounter << std::endl;

    std::cout<<"\nImplementation II : \n" << std::endl;
    stepsCounter = 0;
    hanoiTower(n, start, end);
    std::cout<<"Total Moves = " << stepsCounter << std::endl;
    std::cout<<std::endl;

    return 0;
}

// Tower of hanoi problem