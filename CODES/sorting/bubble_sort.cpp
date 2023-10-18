#include<iostream>
using namespace std;

void show(int*arr,int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

int buuble_sort(int*arr,int n){
    //2 3 1 0 5
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
            int temp =arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            ++c;
            }
       
        }
        show(arr,n);
    }
    cout<<"swapps: "<<c<<endl;
   
}

int main(){
    int a[7]={9,4,1,0,5,2,3};
    buuble_sort(a,7);
    show(a,7);
}