#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> arr={1,2,3,4,5};
    int n=arr.size()-1;
    int i=3;
    while(i<n){
        swap(arr[i],arr[n]);
        ++i;
        --n;
    }
    n=arr.size();
    for (int j = 0; j < n; j++)
    {
        cout<<arr[j];
    }
    
return 0;
}