#include<iostream>
using namespace std;  

//7 9 1 2 3
int pivot(int*arr,int n){
    int i=0,j=n-1,mid;
    while(j>0 ){
        mid= i + (j-i)/2;
        if(arr[mid]>arr[mid+1]){
            return arr[mid+1];
            cout<<"m"<<arr[mid+1]<<endl;
        }
        else
        j=mid;
        cout<<j<<endl;
    }
    return -1;
}

int main(){
    int arr[4]={2,4,8,1};
    cout<<pivot(arr,4);
    return 0;
}