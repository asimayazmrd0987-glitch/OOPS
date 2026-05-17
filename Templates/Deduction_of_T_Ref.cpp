#include<iostream>
using namespace std;


template <typename T>
void inspect(const T& val){
    cout<<"Type size "<<sizeof(T) <<" Bytes\n";
}

int main(){
    inspect(2);
    inspect(23.1);
    inspect("Hello  Viewers (14/May/2026)");
}
// Type size 4 Bytes
// Type size 8 Bytes
// Type size 29 Bytes