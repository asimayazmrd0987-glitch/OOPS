#include<iostream>
using namespace std;

template<typename T>
T square(T x){
    return x * x;
}

int main(){
    cout<<square(4); //it deduct T bu his argument which is send to it....
}