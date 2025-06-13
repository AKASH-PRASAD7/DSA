#include<iostream>
#include<vector>
using namespace std;

  
int sumOfN(int *arr, int start, int end){

    if(start==end){
        return arr[start];
    }

    return arr[start] + sumOfN(arr,start+1,end);
    

}


int reverse (int num){
    /**
     * @brief 
     * 
     * num - 3456
     * 
     * rev(num) = last(num) + rev(rest)
     * 6 +354
     * 
     * rev(num) = rev(456) + 3
     */

    //2nd

    
     if(num/10 == 0){
        return num;
     }


     int firstDigit = num % 10;

     return firstDigit*10 + (num/10);



     //1st apprach fails for 0

    //  if(num/10 == 0){
    //     return num;
    //  }

    //  int lastDigit = num % 10;

    //  int resRev =  reverse(num/10);

    //  int tenth = 1;

    //  int findTenth = resRev;
    //  while (findTenth !=0)
    //  {
    //     tenth *=10;
    //     findTenth = findTenth/10;
    //  }

    //  return lastDigit*tenth + resRev;
     

}

bool isSorted (int *arr,int size, int i, int j){
    /**
     * @brief is sorted array using recursion
     * 
     * 
     * 
     */
 
      if(j==size){
         cout<<"Sorted";
         return true;
      }
      if(arr[i]>arr[j]){
         cout<<"unSorted";
         return false;
      }
      isSorted(arr,size,++i,++j);
}

vector<int> findNumOccur(vector<int> &arr, int i,int key){

    vector<int> ans;

    if(i == arr.size()){
        return ans;
    }
    
    if(arr[i]==key){
        ans.push_back(i);
    }

    vector<int> rem = findNumOccur(arr,++i,key);

    if(rem.size()){
        for(int i=0; i<rem.size(); i++){
            ans.push_back(rem[i]);
        }
    }

    return ans;

}

int roatatedBinarySearch(vector<int> &arr, int start, int end, int key){
    /**
     * @brief Rotated b search
     * - possible cases
     *  [5,1,2,3,4], 
     *  
     * key = 3
     * - case 1 
     * - mid < end (right is sorted) && key>mid && key<end => start = mid+1
     * - else start = mid-1
     * 
     * - case 2 start<mid (left is sorted) key<mid && key>start => end = mid-1
     * - else start = mid+1
     * 
     * 
     */
    if(start>end){
        return -1;
    }
   
     int mid = start + (end-start)/2;

    cout<<start<<mid<<end<<key<<endl;
     if(arr[mid]==key){
        return mid;
     }

    // Case 1: Right half is sorted
     if(arr[mid]<arr[end]){
        if(key>=arr[mid] && key<=arr[end]){
       return roatatedBinarySearch(arr,mid+1,end,key);
    }else{
      return roatatedBinarySearch(arr,start,mid-1,key);
    }
 }
 // Case 2: Left half is sorted
     if(arr[start]<arr[mid] ){
        if( key>=arr[start] && key<=arr[mid]){

            return roatatedBinarySearch(arr,start,mid-1,key);
        }else{
          return roatatedBinarySearch(arr,mid+1,end,key);
        }
    }
     return -1;

}   

void pattern (int n){

    if(n==0){
        return;
    }

    for(int i=0; i<n; i++){
        cout<<"*";
    }

    cout<<endl;

    pattern(n-1);
}

string removeA(string s, string &ans){

    if(!s.size()){
       return "";
    }

    if(s[0]!='a'){
        ans += s[0];
    }

    return removeA(s.substr(1),ans);
}

string skipApple( string s,string &ans){

    if(!s.size()){
        return "";
     }

     if(s.substr(0,5)=="apple"){
        ans =  skipApple(s.substr(5),ans);
     }else{
        ans = s[0] + skipApple(s.substr(1),ans);
     }

     return ans;

}

string subsets(string take, string s, string &ans){
    /**
     * @brief find all subsets (abc)
     * algo take one char form s or ignore
     * 
     *  - take/s
     *  
     * 
     */

     if(s.empty()){
       return ans+= " "+take;
     }

     //take
     subsets(take+s[0], s.substr(1),ans);

     //ignore
     subsets(take,s.substr(1),ans);

     return ans;
}   

int main(){
    vector<int> arr = {5,6,7,8,1,2,3,4};
      
    // cout<<"sum: "<<sumOfN(arr,0,6);
    // cout<<roatatedBinarySearch(arr,0,7,6);
    // pattern(6);

    string s ="abc";
    string ans ="";
        subsets("",s,ans);
    cout<<ans;
    

}
