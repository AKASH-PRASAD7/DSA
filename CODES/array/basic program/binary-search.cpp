#include<iostream>
using namespace std;

int recursive_bsearch(int*arr,int key,int i,int j){
    if(i>j){
        return -1;
    }
    int mid=(i+j)/2;
    if(arr[mid]==key){
        return mid;
    }
    else
    if(key>arr[mid]){
        recursive_bsearch(arr,key,mid+1,j);
    }
    else{
        recursive_bsearch(arr,key,i,mid-1);
    }
}

//1 2 3 4 5 6 7
int iterative_bsearch(int*arr, int size,int key){
    int i=0,j=size-1,mid;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]==key){
            return mid;            
        }
        else
        if(key>arr[mid]){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter:";
    cin>>n;
    int arr[9]={1,2,3,4,5,6,7,18,20};
    // cout<<iterative_bsearch(arr,9,n);
     cout<<recursive_bsearch(arr,n,0,8);

    return 0;
}