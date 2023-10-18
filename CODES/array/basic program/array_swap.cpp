#include<iostream>
using namespace std;
void swap(int arr[], int size){
        int i=0,j=1,temp;
        for(int a=0;a<size;a++){
            if((i>=size)||(j>=size)){
                break;
            }
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i+=2;
            j+=2;
            
        } 
        cout<<endl;
        cout<<"Swapped array"<<endl;
        for(int b=0;b<size;b++){
            cout<<"Element"<<b<<"- "<<arr[b]<<" "<<endl;
        }
    }
int main(){
   
    int arr[9]={1,2,3,4,5,7,3,1,2}; //214375132
    swap(arr,9);

}