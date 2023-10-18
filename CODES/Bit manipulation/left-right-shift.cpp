#include<iostream>
using namespace std;

int main(){
    
    int a=8;

    //left shift
    cout<<"left shift of "<<a<<" by "<<1<<" = "<<(a <<1)<<endl;
    cout<<"left shift of "<<a<<" by "<<2<<" = "<<(a <<2)<<endl;

    //Right shift
    cout<<"Right shift of "<<a<<" by "<<1<<" = "<<(a >> 1)<<endl;
    cout<<"Right shift of "<<a<<" by "<<2<<" = "<<(a >> 2)<<endl;

    return 0;
}