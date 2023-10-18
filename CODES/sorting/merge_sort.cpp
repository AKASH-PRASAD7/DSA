#include<iostream>
using namespace std;

// 9,4,1,0,5,2,3

// 1 2 3 4
//1 2 4  3 4


void show(int*arr,int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}
//i    j
//1 2  3 4 5

void merge(int* arr, int s, int mid, int e){
  int i=s;
  int j=mid+1;
  int arr1[10];
  int k=0;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            arr1[k]=arr[i];
            i++;
            k++;
        }
        else{
            arr1[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        arr1[k]=arr[i];
        i++;
        k++;
    }
       while(j<=e){
        arr1[k]=arr[j];
        j++;
        k++;
    }

 for (int a = 0; a < e - s + 1; a++) {
        arr[s + a] = arr1[a];
    }

}
// l         h
// 1 2 | 3 4 5

//l   h
//1 | 2

void merge_sort(int* arr,int s ,int n){
  if(s>=n){
      return ;
  }

  
  int mid = (s + n)/2;
  //left


  merge_sort(arr,s,mid);

  //right
  merge_sort(arr,mid+1,n);
  
  merge(arr,s,mid,n);
  
  
}
    

int main(){
    int a[5]={1,4,0,2,3};
  
    int n=5;
    merge_sort(a,0,n-1);
    // merge(a,0,1,5);
    show(a,5);
}