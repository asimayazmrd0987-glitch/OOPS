#include<iostream>
using namespace std;

int* stackProblem(){
  int x=12;
  return &x;
}
int* heapProblem(){
    int* p=new int (13);
    return p;
} 
int main(){
  int *bad =stackProblem();
  int *Good =heapProblem();
  cout<<Good;
  delete Good;
  Good=nullptr;
  return 0;
}
