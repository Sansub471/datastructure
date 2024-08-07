#include"arrays.h"

// default constructor
template <typename T> Array<T>::Array():A(nullptr), N(0){};

// creating object with parameterized constructor, passing array.
// T arr[] is same as T* arr
template <typename T> Array<T>::Array(T* arr, unsigned int size){
    A = new T[size];
    N = size;
    for(int i=0; i < size; i++){
        A[i] = arr[i];
    }
}

// default destructor to free allocated memory
// template <typename T> Array<T>::~Array(){
//     //std::cout<<"This is array deconstructor."<<std::endl;
//     //std::cout<<"Trying to free : " << A << std::endl;
//     delete[] A;
// }

// get the size of the array
template <typename T> unsigned int Array<T>::getSize(){
    return N;
}

// get the head of the array
template <typename T> T* Array<T>::getArray(){
    return A;
}

// input array from user
template <typename T> T* Array<T>::InputArray(){
    std::cout<<"Give the size of array : "; std::cin>>N;
    // Allocate memory for array and get the input.

    try{
        A = new T[N];
    }

    catch(const std::bad_alloc& e){
        std::cerr<<"Memory allocation failed for the array. "<< e.what()
        <<std::endl;
        A = nullptr; N = 0;
        return nullptr;
    }

    for(int i=0; i < N; i++){
        std::cout<<"Element ["<<i<<"]"; std::cin>>A[i];
    }
    return A;
}

// print the array
// Problem with copying code from standalone function
// Previously : head pointer of the array was passed as local variable
// but now the class's data is being modified hence, make sure to keep track of the head
template <typename T> void Array<T>::PrintArray(){
    if(A == nullptr || N <=0 ){
        std::cerr<<"Can't print empty array!"<<std::endl;
        return;
    }

    T* head  = A;
    for(int i=0; i < N; i++){
        std::cout<<*head<<"\t";
        head++;
    }
    std::cout<<std::endl;
}

// try std::swap() instead
template <typename T> void Array<T>::swap(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

// get an array with random values
template <typename T> T* Array<T>::randomArray(unsigned int size, T minValue, T maxValue){
    N = size;
    if(minValue > maxValue){
        swap(&minValue, &maxValue);
    }

    A = new(std::nothrow) T[N];
    if(A == nullptr){
        std::cerr<<"Memory allocation failed!"<<std::endl;
        return nullptr;
    }

    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Fill the array with random values within the specified range
    for (std::size_t i = 0; i < N; ++i) {
        if constexpr (std::is_integral_v<T>) { // Read : https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/
            A[i] = static_cast<T>((std::rand() % (maxValue - minValue + 1)) + minValue);
        } else {
            // Generate random floating-point numbers with up to 3 decimal places
            double randomValue = (static_cast<double>(std::rand()) / RAND_MAX) * (maxValue - minValue) + minValue;
            randomValue = std::round(randomValue * 1000.0) / 1000.0; // multiply by 1000 round to nearest integer and divide it by 1000
            A[i] = static_cast<T>(randomValue);
        }
    }
    return A;
}