#include<stdio.h>

int binary_iterartive(int a[], int size,int x){
    int low=0;
    int high=size-1,mid;
    

 while(low<=high){

  mid=(low+high)/2;
    if (a[mid]==x){
        return mid;
    }
    else
    if(a[mid]<x){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
 }
 return -1;



}
int binary_recur(int a[],int low,int size,int x){
    {int mid=(low+size)/2;
    if(a[mid]==x){
        return mid;
    }
    else
    if(x<a[mid]){
       
        binary_recur(a,low,mid-1,x);
    }
    else{
        
        binary_recur(a,mid+1,size,x);
    }
    }
   //in recursion dont add return -1 because it alawys satisys

   //dunno why
}
int main()

{          //0 1 2 3  4  5  6  7
    int a[]={1,2,3,4,5,6,7,8};
    int b;
    int s =sizeof(a)/sizeof(int);
   
    b=binary_recur( a,0,s,8);
    if(b!=-1){
        printf("found ");


    }
    else
    printf("not");
    


return 0;
}