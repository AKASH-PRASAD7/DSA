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


vector<vector<int>> subset(vector<int> &arr){
    /**
         * @brief Algorithm to generate all subsets of an array
         * 
         * Example: Input array [1, 2, 3]
         * Output: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
         * 
         * Steps:
         * 1. Start with an empty subset: ans = [[]].
         * 2. For each element in the array:
         *    a. Create new subsets by adding the current element to all existing subsets in `ans`.
         *    b. Store these new subsets temporarily in `levelans`.
         *    c. Add all subsets in `levelans` to `ans`.
         * 3. Repeat for all elements in the array.
         * 4. Return the final `ans` containing all subsets.
         * 
         * Example Walkthrough:
         * Input: [1, 2, 3]
         * Step 1: Start with ans = [[]].
         * Step 2: Process element 1:
         *         New subsets = [[1]]
         *         ans = [[], [1]]
         * Step 3: Process element 2:
         *         New subsets = [[2], [1, 2]]
         *         ans = [[], [1], [2], [1, 2]]
         * Step 4: Process element 3:
         *         New subsets = [[3], [1, 3], [2, 3], [1, 2, 3]]
         *         ans = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
         * Step 5: Return ans.
    */

     vector<vector<int>> ans;

     ans.push_back({});

     for(int i=0; i<arr.size(); i++){

        vector<vector<int>> levelans;

        for(int j=0; j<ans.size(); j++){

            vector<int> temp = ans[j];
            temp.push_back(arr[i]);
            levelans.push_back(temp);

        }
        
        for(int k=0; k<levelans.size(); k++){
            vector<int> temp1 = levelans[k];
            ans.push_back(temp1);
        }

     }
     return ans;

}

void findPermutation(string processed, string unprocessed,vector<string> &perm){
    
    if(!unprocessed.size()){
        perm.push_back(processed);
        return;
    }



    for(int i=0; i<=processed.size(); i++){
        string newProcessed = processed.substr(0, i) + unprocessed[0] + processed.substr(i);
        findPermutation(newProcessed, unprocessed.substr(1), perm);
    }

 
}

void permutation(string s){
    /**
     * @brief permutations
     * return all permuataion of s(abc)
     *  
     *          processed/unproceesed
     *          
     *              ""/(abc)
     *                  |
     *               "_a_"/(bc)
     *                 /       \
     *         "_b_a_"/(c)      "_a_b_"/(c)
     *         /   |      \        /   |    \
     *  "cba"/"" bca/""  bac/"" cab/"" acb/""  abc/""  => ans
     *        
     */

     string processed = "";
     string unprocesed = s;

     vector<string> perm;

     findPermutation(processed,unprocesed,perm);

     for(int i=0; i<perm.size(); i++){
        cout<<perm[i]<<endl;
    }
}

int main(){
    vector<int> arr = {1,2,3};
      
    // cout<<"sum: "<<sumOfN(arr,0,6);
    // cout<<roatatedBinarySearch(arr,0,7,6);
    // pattern(6);

    // string s ="abc";
    // string ans ="";
    //     subsets("",s,ans);
    // cout<<ans;
    
    // vector<vector<int>> ans = subset(arr);

    // for(int i=0; i<ans.size(); i++){
    //     for(int j=0; j<ans[i].size(); j++){
    //         cout<<"["<<ans[i][j]<<"] ";
    //     }
    //     cout<<endl;
    // }
    permutation("abc");
}
