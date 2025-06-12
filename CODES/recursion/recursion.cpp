#include<iostream>
using namespace std;

  
int sumOfN(int *arr, int start, int end){

    if(start==end){
        return arr[start];
    }

    return arr[start] + sumOfN(arr,start+1,end);
    

}


int main(){
    int arr[] = {2,4,5,5,6,2,8};
      
    cout<<"sum: "<<sumOfN(arr,0,6);
}
