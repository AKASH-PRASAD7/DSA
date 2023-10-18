#include<iostream>
using namespace std;

//aaa  r=3 c=3 for 1=>a 2=>b
//bbb
//ccc

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//     char ch ='a';
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n;j++){
//         //    cout<<('A'+i-1);
//         cout<<ch;
//         }
//         ch++;
//         cout<<endl;
//     }
    
// }

//abc
//abc
//abc

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//     char ch ;
//     for(int i=1; i<=n; i++){
//         for(int j=0; j<n;j++){
        
//          ch ='a'+j;
//          cout<<ch;
//         }
        
//         cout<<endl;
//     }
    
// }

//abc
//bcd  r=3/n c=3  pn= i+j-1
//cde   

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//     char ch; 
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n;j++){
//            ch='@'+i+j-1;
//            cout<<ch;
//         }
       
        
//         cout<<endl;
//     }
    
// }

//d     r=1 c=1  
//cd    r=2 c=1,2
//bcd
//abcd   

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//     char ch; 
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i;j++){
//            ch='@'+i+j-1;
//            cout<<ch;
//         }
//         cout<<endl;
//     }  
// }

//___*  r=4 
//__**   s=3
//_***   1=i+a-1
//****

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//      int c=1;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n-i;j++){
//            cout<<" ";
//         }
//         for(int a=1;a<=i;a++){
//             cout<<c;
//             c++;
//         }
//         cout<<endl;
//     }  
// }

//****  r=4 s=i-1 *=n-i+1
//_***   
//__**
//___*


int main(){
    int n;
    cout<<"enter no ";
    cin>>n;
     
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i-1;j++){
           cout<<" ";
        }
        for(int a=1;a<=n-i+1;a++){
            cout<<i+a-1;
        }
        cout<<endl;
    }  
}