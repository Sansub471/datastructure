#include<stdio.h>

int OneDimArray(int A[]){
    // int A[] is seen as int* by the compiler
    return *(A+1); // just random

}

int TwoDimArray(int B[][3]){
    // only first dimension is allowed to left empty
    return *(*B + 1);
}


int ThreeDimArray(int C[][2][2]){
    return ***C;
}
int main(){
    int A[5] = {1,2,3,4,5};
    int B[2][3] = {{4,5,7},{9,13,17}};
        int C[3][2][2] = {
        {
            {2,5},{7,9}
        },
        {
            {3,4},{6,1}
        },
        {
            {0,8},{11,13}
        }
    };
    printf("OneDimArray Function   : %d\n", OneDimArray(A));
    printf("TwoDimArray Function   : %d\n", TwoDimArray(B));
    printf("ThreeDimArray Function : %d\n", ThreeDimArray(C));
    return 0;
}