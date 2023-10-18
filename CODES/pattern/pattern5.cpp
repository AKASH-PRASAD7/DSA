#include<iostream>
using namespace std;

//     1 
//    121
//   12321
//  1234321
// 123454321


// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
     
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n-i;j++){
//           cout<<" ";
//         }
//         for(int a=1;a<=i;a++){
//            cout<<a;
//         }
//         for(int b=1;b<=i-1;b++){ 
//          cout<<i-b;           
//         }
//         cout<<endl;
//     }  
// }

//12345*54321
//1234**4321  
//123***321 
//12****21
//1*****1

int main(){
    int n;
    cout<<"enter no ";
    cin>>n;
     
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1;j++){
         cout<<j;
        }
        for(int a=1;a<=i;a++){
           cout<<"*";
        }
        for(int b=1;b<=n-i+1;b++){ 
                 cout<<n-b-i+2;
        }
        cout<<endl;
    }  
}
