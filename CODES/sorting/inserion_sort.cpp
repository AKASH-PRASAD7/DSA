#include<iostream>
using namespace std;

void show(int*arr,int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

int inserion_sort(int*arr,int n){
    //2 3 1 0 5
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        show(arr,n);
        arr[j+1]=key;
    }
}

int main(){
    int a[7]={9,4,1,0,5,2,3};
    inserion_sort(a,7);
    show(a,7);
}