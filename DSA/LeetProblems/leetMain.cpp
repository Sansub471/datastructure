#include<iostream>

#include"../localLib/treeTraversalPrint.hpp"

#include"reverseInteger.hpp"
#include"sumWithoutOperator.hpp"
#include"mergeSortedArrays.hpp"
#include"medianOfTwoSortedArray.hpp"

#include"fourSum.hpp"
#include"simplifyPath.hpp"
#include"romanToInt.hpp"

#include"searchMatrix.hpp"
#include"combinationSum.hpp"

int main(){
    // reverse an integer
    int x = 123;
    int revx = reverseInteger(x);
    std::cout<<"The reverse of " << x <<" is " << revx << std::endl;

    // sumwithout + or - operator
    std::cout<<"The sum  = "<< getSum(5, 7) << std::endl;
    std::cout<<"The difference = " << subtract(12, 5) << std::endl;

    // merge two sorted arrays
    std::vector<int> nums1 = {1,2,3};
    std::vector<int> nums2 = {2,5,6};
    int m = nums1.size();
    nums1.resize(nums1.size() + nums2.size(), 0);
    int n = nums2.size();
    mergeSortedInplace(nums1, m, nums2, n);
    std::cout<<"The merged vector inplace : ";
    Traversal::printVector1D(nums1); std::cout<<std::endl;

    // merge sorted arrays and find median
    std::vector<int> n1 = {1,3};
    std::vector<int> n2 = {2};
    findMedianSortedArrays(n1, n2);

    // four sum problem
    std::vector<int> fsum{1,0,-1,0,-2,2};
    std::vector<std::vector<int>> _4Sums = fourSum(fsum, 0);
    

    // simplify path
    std::string path = "/home/name/usr/../abc/../../../////./././/b/c//";
    std::string simplePath = simplifyPath(path);

    // Convert roman number to integer
    std::string roman = "MMMDCCCLXXXVIII";
    int romanInt = romanToInt(roman);
    std::cout<<"\nThe roman: " << roman << "to int : " << romanInt <<std::endl;

    // search matrix
    std::vector<std::vector<int>> matrix {{-10},{-5},{-7}};
    int target = -10;
    bool matFound = searchMatrixI(matrix, target);
    std::cout<<"\nThe search result is : " << matFound << std::endl;

    // combination sum
    std::vector<int> candidates {6,3,2,7};
    target = 7;
    std::vector<std::vector<int>> combinations  = combinationSum(candidates, target);
    std::cout<<"\nThe combinations are : ";
    Traversal::printVector2D(combinations);

    // Combination Sum II
    candidates = {2,1,2,5,2};
    target = 5;
    combinations = combinationSum2(candidates, target);
    std::cout<<"\nThe combinations are : ";
    Traversal::printVector2D(combinations);
    return 0;
}