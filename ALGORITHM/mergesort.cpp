#include<iostream>
using namespace std;

int merge(int a[], int low,int mid, int high){
    int i=low,j=high,k=0;
    int b[high];
    while((i<=mid)&&(j<=high)){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;

        }
        else{
            b[k]=a[j];
            k++;
            j++;
        }

    }
    if(i>mid){
        while(j<=high){
            b[k]=a[j];
        k++;
        j++;

        }
        

    }
    else
    {
        while(i<=mid){
             b[k]=a[i];
        k++;
        i++;
        }
    }
    for (i = 0; i < high; i++)
    {
        cout<<b[i]<<" ";
    }
    


}
void merge_sort(int a[], int low, int high){
    int mid=(low+high)/2;
    if(low<high){
        merge_sort(a,low,mid-1);
        merge_sort(a,mid,high);
        merge(a,low,mid,high);
    }
}
int main()
{
   int a[]={2,4,1,0,9,6,3,7};
   int s=sizeof(a)/sizeof(int);
   merge_sort(a,0,s);
   return 0; 
}
