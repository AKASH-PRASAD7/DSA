#include<iostream>
using namespace std;
int main(){
    int n;
    string ans="";
    cout<<"Enter Number to Convert:";
    cin>>n;
    if(n==0) ans='0';
    int remainder;
    while(n>0){
         remainder=n%2;
         n=n/2;
         ans.insert(0, to_string(remainder));    
    }
    cout<<endl;  
    cout<<"Binary is: "<<ans;
    return 0;
}