#include <array>
#include <iostream>

//using namespace std;

std::array<int, 4> arr1; //길이 무조건 명시
arr1 = {11,12,13,14};
arr1[3] = 15; //arr1.at(3) = 15;

std::array<int, 5> arr2 = {0,1,2,3,4}; 

for(const auto& i : arr2){
  std::cout<<" "<<i;  
}

std::array<double, 6> arr3;

//begin, back
