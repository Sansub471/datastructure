#include<iostream>
// Functor with a member variable

class Add_To_Sum {

  private:
    int initial_sum;

  public:

    // constructor to initialize member variable  
    Add_To_Sum(int sum) {
      initial_sum = sum;
    }

    // overload function call operator
    int operator()(int num) {
      return initial_sum + num;
    }

};

int main() {

  // create object of Add_To_Sum class
  // initialize member variable of object with value 100
  Add_To_Sum add = Add_To_Sum(100);

  // call the add object with 78 as argument
  int final_sum = add(78);

  std::cout << "100 + 78 = " << final_sum << std::endl;

  return 0;
}