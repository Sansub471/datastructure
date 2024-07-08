#include<iostream>

template <typename T> void swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T> void PrintArray(T* A, unsigned int N){
    if(A == NULL){
        std::cout<<"Can't print NULL array!\n";
        return;
    }
    std::cout<<"The elements are : ";
    unsigned int i;
    for(i=0; i<N; i++){
        std::cout<<"\t"<< *A;
        A++;
    }
    std::cout<<std::endl;

}

template <typename T> void bubbleSort(T* A, unsigned int N){
    int i,j;
    for(i=0; i< N - 1; i++){
        bool swapped = false;
        for(j=0; j< N - i - 1; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                swapped = true;
            }
        }
        //printf("Pass : %d\n", i);
        //PrintArray(A, N);

        // if no two elements swapped by inner loop, break
        if(swapped == false) break;
    }
}


int main(){
    int A[] = {89, 34, 1, 3, -15, 37, 12, 23, 21, 10};
    unsigned int N = sizeof(A) / sizeof(A[0]);
    std::cout<<"The given array is : \n";
    PrintArray(A, N);
    std::cout<<std::endl;

    bubbleSort(A, N);
    std::cout<<"The sorted array is: \n";
    PrintArray(A, N);
    std::cout<<std::endl;

    float B[] = {89.2, 34.6, 1.1, 3.3, -15.15, 37.36, 12.12, 23.23, 21.21, 10.1};
    unsigned int M = sizeof(B) / sizeof(B[0]);
    std::cout<<"The given array is : \n";
    PrintArray(B, M);
    std::cout<<std::endl;

    bubbleSort(B, M);
    std::cout<<"The sorted array is: \n";
    PrintArray(B, M);
    std::cout<<std::endl;

    
    return 0;
}