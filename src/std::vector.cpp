#include <vector>
#include <iostream>

//using namespace std;

std::vector<int> v1;
v1 = {11,12,13,14}; //c++11
v1[3] = 15; //v1.at(3) = 15;

std::vector<int> v2 = {0,1,2,3,4}; 

for(const auto& i : v2){
  std::cout<<" "<<i;  
}
//v1.size() 벡터 길이

std::vector<double> v3;

//begin, end(끝주소 + 1)

//function
//insert(위치, 값); : 원소 추가
//push_back(값); : 가장 마지막에 원소 추가
//erase(위치); : 원소 삭제
//erase(시작위치, 끝위치) : 범위 지우기
//pop_back(); : 가장 마지막 원소 제거
