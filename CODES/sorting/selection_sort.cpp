#include<iostream>
using namespace std;

void show(int*arr,int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<",";
    }
}

int selection_sort(int*arr,int n){
    //2 3 1 0 5
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){
    int a[7]={9,4,1,0,5,2,3};
    selection_sort(a,7);
    show(a,7);
}