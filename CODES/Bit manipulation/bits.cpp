#include<iostream>
using namespace std;

int main(){
    
    int a=2;
    int b=3;
    //AND
    cout<<"And of "<<a<<" , "<<b<<" = "<<(a & b)<<endl;

    //OR
    cout<<"OR of "<<a<<" , "<<b<<" = "<<(a | b)<<endl;

    //NOT
    cout<<"NOT of "<<a<<" = "<<(~a)<<endl;

    //XOR
    cout<<"XOR of "<<a<<" , "<<"4"<<" = "<<(a ^ 4)<<endl;

    return 0;
}