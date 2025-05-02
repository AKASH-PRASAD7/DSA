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


//NEW

int iterative_binarySearch(int* arr,int size,int key){
    /*
    0) array must be sorted
    1) initialize i with 0 and j=with last-1 and find mid
    2) for 1,2,3,4,5,6,7,8,9,10 i=0,j=10,mid=i+(j-i)/2=5 
    3) if mid=key return otherwise if mid>key (i=0,j=mid-1) search in left part else vice versa
    4) stop if j>=i
    */

    // Check for empty array or invalid size early
    if (arr == NULL || size <= 0) {
        return -1;
    }

    int i=0;
    int j=size-1;
    int mid;

    while(i<=j){
        mid=i+(j-i)/2;
        if(arr[mid]==key){
            return mid;
        }
        //left sub array
        if(key<arr[mid]){
            j=mid-1;
        }//right sub array
        else{
            i=mid+1;
        }
    }
    return -1;
}


int recursive_binarySearch(int*arr,int low,int high,int size,int key){
    /*
    1)Array must be sorted not null with non zero size
    2)params *arr,low,high,size,key
    3)find mid=i+(j-i)/2, if key=mid return
    4) if key<mid high=mid-1, search in left sub array otherwise vice versa
    5) stop if low>high
    */

    if(arr==NULL||size<=0||low>high){
        return -1;
    }


    int mid=low+(high-low)/2;

    if(arr[mid]==key){
        return mid;
    }

    //left sub array
    if(arr[mid]>key){
      return recursive_binarySearch(arr,low,mid-1,size,key);
    }//right subarray
    else{
      return  recursive_binarySearch(arr,mid+1,high,size,key);
    }

}

int main(){
    int n;
    cout<<"enter key to search:";
    cin>>n;
    int arr[9]={1,2,3,4,5,6,7,18,20};
    // cout<<iterative_bsearch(arr,9,n);
     cout<<"index at: "<<recursive_binarySearch(arr,0,8,9,n);

    return 0;
}