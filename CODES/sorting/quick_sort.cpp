#include<iostream>
using namespace std;

void show(int*arr,int n){
    for(int i=0; i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}

// 1 2 5 7 8 9

// p i       j
// 7 5 1 8 2 9
// p>i => swap(p,i) p=i i++
//not i++
//
int partition(int* arr ,int l,int h){
    int low=l;
    int high=h;
    int pivot=l;

    while(low<high)
    {
    if(arr[low]<=arr[pivot] ){
        low++;
       
    }
    else
    if(arr[high]>arr[pivot] ){
        high--;
       
    }
    else {
            swap(arr[low], arr[high]);
            low++;
            high--;
            
        }
    
    }
    swap(arr[pivot],arr[high]);
  
    return high;
}

void quick_sort(int*arr,int l,int h){
    // int low=l;
    // int high=h;
    // int pivotindex;
    // if(low<high){
    // pivotindex=partition(arr,low,high);
    // quick_sort(arr,low,pivotindex - 1);
    // quick_sort(arr,pivotindex + 1,high);
    // }
    if (l < h) {
        int pivotindex = partition(arr, l, h);
        quick_sort(arr, l, pivotindex - 1);
        quick_sort(arr, pivotindex + 1, h);
    }
}

int main(){
    int a[7]={9,4,1,0,5,2,3};
    // quick_sort(a,0,6);
    int a1 = partition(a,0,6);
    cout<<a1<<endl;
    show(a,7);
   a1= partition(a,0,5);
    cout<<a1<<endl;
    show(a,7);
}