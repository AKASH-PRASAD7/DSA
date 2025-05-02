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


int noOfOccurence(int *arr,int size,int key){
	/**
	 * @param *arr,size, key,
	 * @pre Not null array with size>0
	 * 1) two variables for storing 1st and last occurenece index initalize with -1
	 * 2) iterate over array 
	 * 3) if found update 1st and last occurence, and if found again only update last occurence
	 * 4) if 1st occurence or last occurence is -1 return not found
	 */
	if(arr==NULL||size<=0){
		cout<<"Inavlid array";
		return -1;
	}
	int first_occur=-1;
	int last_occur=-1;

	for(int i=0;i<size;i++){
		if(arr[i]==key){
			if(first_occur==-1){
				first_occur=i;
				last_occur=i;
			}else{
				last_occur=i;
			}
		}
	}
	if(first_occur==-1){
		cout<<"Not found";
		return -1;
	}
	cout<<"first occur: "<<first_occur<<" last occur: "<<last_occur;
	return 1;
}

int main(){
    int n;
    cout<<"enter:";
    cin>>n;
    int arr[9]={1,2,3,4,5,5,5,18,20};
    // cout<<iterative_bsearch(arr,9,n);
    // occurence(arr,9,n);
    noOfOccurence(arr,9,n);

    return 0;
}