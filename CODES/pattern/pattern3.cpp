#include<iostream>
using namespace std;

// *
// **
// ***

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//     int count=1;
//     for(int i=1; i<=n; i++){
//         for(int j = 1;  j<=i;j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
    
// }

// 1
// 22
// 333

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//     int count=1;
//     for(int i=1; i<=n; i++){
//         for(int j = 1;  j<=i;j++){
//             cout<<i;
//         }
//         cout<<endl;
//     }
    
// }

// 1
// 23
// 456

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
    
//     for(int i=1; i<=n; i++){
     
//         for(int j = 0;  j<i;j++){
//             cout<<i+j;
            
//         }
//         cout<<endl;
//     }
    
// }

// 1      r=4/n c = 1r => 1 2r=> 21 3r=>321

// 21
// 321
// 4231

int main(){
    int n;
    cout<<"enter no ";
    cin>>n;
    int count ;
    for(int i=1; i<=n; i++){  
        // count =i;      
     for(int j = 1;  j<=i;j++){
         cout<<(i-j+1);
        //  count--;
        }
        cout<<endl;
    }
    
}

//aaa
//bbb
//ccc