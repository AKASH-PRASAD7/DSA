#include<iostream>
using namespace std;

// 1234
// 1234  
// 1234
// 1234

// int main(){
//     int n;
//     cout<<"enter no ";
//     cin>>n;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n;j++){
//             cout<<j;
//         }
//         cout<<endl;
//     }
    
// }

// 123 for row =3
// 456
// 789

int main(){
    int n;
    cout<<"enter no ";
    cin>>n;
    int count=1;
    for(int i=1; i<=n; i++){
      
        for(int j=1; j<=n;j++){
            cout<<" "<<count<<" ";
            count++;
            
        }
        cout<<endl;
    }
    
}