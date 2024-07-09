#ifndef ARRAY_CLASS
#define ARRAY_CLASS
template <typename T> class Array{
    private:
        T* A;
        unsigned int N; // array size
    public:
    Array();
    Array(T* arr, unsigned int size);

    unsigned int getSize();
    T* InputArray();
    void PrintArray();    
};
#endif