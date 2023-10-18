#include<iostream>
using namespace std;

void occurence(int*arr,int n, int x){
    int i=0,j=n-1,mid,a=-1,b=-1;
	
	while(i<=j){
		mid= i +(j-i)/2;
		if(arr[mid]==x){
			a=b=mid;
			
			while((arr[a-1]==x)&&(a!=-1)){
				--a;
				               				
			}
            while((arr[b+1]==x)&&((b+1)<n)){
                ++b;
             
            }
			cout<<"First occurence: "<<a<<endl;
			cout<<"Last occurence: "<<b<<endl;
			cout<<"NO of count: "<<(b-a)+1<<endl;
            break;
		}
		else if (x>arr[mid]){
			i=mid+1;
		}
		else{
			j=mid-1;
		}
	}
	cout<<"not found";
}

int main(){
    int n;
    cout<<"enter:";
    cin>>n;
    int arr[9]={1,2,3,4,5,5,5,18,20};
    // cout<<iterative_bsearch(arr,9,n);
    occurence(arr,9,n);

    return 0;
}