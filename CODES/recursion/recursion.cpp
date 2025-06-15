#include<iostream>
#include<vector>
#include <utility>
#include <unordered_map>
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

int maze(int row,int col){
    /**
     * @brief Maze
     * go from start to end and find how many ways
     *             
     *            0      1     2
     *        0[ (0,0) (0,1) (0,2) ]
     *        1[ (1,0) (1,1) (1,2) ]
     *        2[ (2,0) (2,1) (2,2) ]
     * 
     * from(0,0) to (2,2) directions -> right/down
     * 
     */

     if(row==2 || col==2){
        return 1;
     }


     //go right
     int right = 0;

     if(col<2){
     right = maze(row,col+1);
     }

     //go down
     int down = 0;

     if(row<2){
        down = maze(row+1,col);
     }

     return right+down;
}

void mazePath(int row,int col,string currPath, vector<string> &path){

    
    if(row==2 && col==2){
            path.push_back(currPath);
            return;
     }


     //go right
     if(col<2){
        mazePath(row,col+1,currPath+"R", path);
     }

     //go down
     if(row<2){
         mazePath(row+1,col,currPath+"D",path);
     }

}
void mazePath2(int row,int col,string currPath, vector<string> &path){

    
    if(row==2 && col==2){
            path.push_back(currPath);
            return;
     }


     //go right
     if(col<2){
        mazePath(row,col+1,currPath+"R", path);
     }

     //go diagonal
     if(col<2 && row<2){
        mazePath(row+1,col+1,currPath+"D", path);
     }

     //go down
     if(row<2){
         mazePath(row+1,col,currPath+"D",path);
     }

}

void mazePathWithBacktracking(int row,int col,string currPath, vector<string> &path,vector<vector<int>> &maze){
   
    //in all direction up,down,left,right
    // for each traversal make sure we dont traverse visited agian
    // after each trvaersal mark cell as unvisited for other paths
       /**
     * @brief Maze
     * go from start to end and find how many ways
     *             
     *            0      1     2
     *        0[ (0,0) (0,1) (0,2) ]
     *        1[ (1,0) (1,1) (1,2) ]
     *        2[ (2,0) (2,1) (2,2) ]
     * 
     * from(0,0) to (2,2) directions -> up/down/left/right/diagonal
     * 
     *
     * **/

    int totalRow = maze.size()-1;
    int totalCol = maze[0].size()-1;

    

    //if visited return
    if(maze[row][col]){
        return;
    }

    //after visiting mark as visited
    maze[row][col]=1;

    if(row==2 && col==2){
            path.push_back(currPath);
            maze[row][col] = 0; 
            return;
     }



     //go right
     if(col<totalCol){
        mazePathWithBacktracking(row,col+1,currPath+"R", path,maze);
     }

     //go left
     if(col>0){
        mazePathWithBacktracking(row,col-1,currPath+"L", path,maze);
     }

     //go diagonal (btm right)
     if(col<totalCol && row<totalRow){
        mazePathWithBacktracking(row+1,col+1,currPath+",BR,", path,maze);
     }

     //go diagonal (top left)
     if(col>0 && row>0){
        mazePathWithBacktracking(row-1,col-1,currPath+",TL,", path,maze);
     }

     //go down
     if(row<totalRow){
        mazePathWithBacktracking(row+1,col,currPath+"D",path,maze);
     }
     //go up
     if(row>0){
        mazePathWithBacktracking(row-1,col,currPath+"U",path,maze);
     }

    //reset
    maze[row][col]=0;
}

void mazePathWithObstacle(int row,int col,string currPath, vector<string> &path){
   
    //assuming (1,1) as obstacle 

    if(row==1 && col==1){

        return;
    }
    
    if(row==2 && col==2){
            path.push_back(currPath);
            return;
     }


     //go right
     if(col<2){
        mazePathWithObstacle(row,col+1,currPath+"R", path);
     }

     //go down
     if(row<2){
        mazePathWithObstacle(row+1,col,currPath+"D",path);
     }

}

bool checkLeftDiagonal (pair<int,int> queeen, pair<int,int> pos,int col){
    //will return true if queen attacks
    //if from pos i can reach queen then queen attacks

    //check bottm left
    if(queeen.first<pos.first && queeen.second<pos.second){
        //considering 4x4 board
        int posR = pos.first;
        int posC = pos.second;

        while(posR>=0 && posC>=0){
            if(posR == queeen.first && posC == queeen.second){
                return true;
            }
            posR--;
            posC--;
        }
    }
    return false;
    //check top left
    //no need since im placing quuens at top first
}

bool checkRightDiagonal (pair<int,int> queeen, pair<int,int> pos,int col){
    //will return true if queen attacks
    //if from pos i can reach queen then queen attacks

    //check bottm left
    if(queeen.first<pos.first && queeen.second>pos.second){
        //considering 4x4 board
        int posR = pos.first;
        int posC = pos.second;

        while(posR>=0 && posC<=col){
            if(posR == queeen.first && posC == queeen.second){
                return true;
            }
            posR--;
            posC++;
        }
    }
    return false;
    //check top left
    //no need since im placing quuens at top first
}

bool isCellSafe (int row,int col,vector<pair<int,int>> &queenPos,int totalCol){
    /**
     * @brief check whether currsne tquerae is safe or not
     * 
     */

     for(int i=0; i<queenPos.size(); i++){

        int queenRow = queenPos[i].first;
        int queenCol = queenPos[i].second;

        //check horizaral
        if(col == queenCol){
            return false;
        }

        //check vertical
        if(row == queenRow){
            return false;
        }

        //check diagona;
        pair<int,int> pos = {row,col};

        //check \ diagnal
        if(checkLeftDiagonal(queenPos[i], pos,totalCol)){
            return false;
        }

        //check / diagonal
        if(checkRightDiagonal(queenPos[i], pos,totalCol)){
            return false;
        }

     }
     return true;
}

int nQueen(int row,int col,int queens,vector<pair<int,int>> &queenPos){
    /**
     * @brief find all ways to pu n quuens in 
     *          nxn chess board so that they dont cancel each other.
     * 
     *      0    1    2   3
     *    --------------------
       0    |   |  q |   |    |
           --------------------
       1    |   |   |   |  q  |
            --------------------
       2    | q  |   |   |    |
            --------------------
       3    |    |   | q  |    |
            --------------------

     *  
        - first place queen in first row 1st cell
        - then make recursion from 2nd row till end
        - loop through each cell and place quuen if area safe
        - if not cuur row not safe then backtrack      
     *  - and place prev quuen in next cell
        
     */
    
            //all quueens placed
            if(queens==0){
                return 1;
            }

    if(row> col){ //since chess board is suaqare
        //safety check
        return -1;
    }



    int totalCol = col;
    bool isSafe = false;
    //move by col
    for(int i=0; i<totalCol; i++){

         isSafe = isCellSafe(row,i,queenPos,totalCol);

            if(isSafe){
                
                 queenPos.push_back({row,i});

                if(nQueen(row+1,totalCol,queens-1,queenPos)){
                    return 1;
                }else{
                    queenPos.pop_back();
                }
            }
    }

    if(!isSafe){
        //if current row is not safe
        return 0;
    }

}

void printBoard(int dimension,vector<pair<int,int>> queenPos){

    unordered_map<string,bool> pos;

    for(int i=0; i<queenPos.size(); i++){
        int f = queenPos[i].first;
        int s = queenPos[i].second;

        string p = to_string(f) + "," + to_string(s);
        
        pos[p] = true;
    }

    for(int i=0; i<dimension; i++){


        for(int j=0; j<dimension; j++){
            
            string p = to_string(i) + "," + to_string(j);

            if(pos[p]){
                cout<<"Q";
            }else{
                cout<<"X";
            }
        
        }
        cout<<endl;

    }

    cout<<endl;
}

int nQueensALL(int row,int col,vector<pair<int,int>> &queenPos){
    /**
     * @brief find all ways to pu n quuens in 
     *          nxn chess board so that they dont cancel each other.
     * 
     *      0    1    2   3
     *    --------------------
       0    |   |  q |   |    |
           --------------------
       1    |   |   |   |  q  |
            --------------------
       2    | q  |   |   |    |
            --------------------
       3    |    |   | q  |    |
            --------------------

     *  
        - first place queen in first row 1st cell
        - then make recursion from 2nd row till end
        - loop through each cell and place quuen if area safe
        - if not cuur row not safe then backtrack      
     *  - and place prev quuen in next cell
        
     */
    
     

    if(row == col){ //since chess board is suaqare
        //safety check
        //all queens places print
        printBoard(col,queenPos);
        return 1;
    }



    int totalCol = col;
    bool isSafe = false;
    //move by col
    for(int i=0; i<totalCol; i++){

         isSafe = isCellSafe(row,i,queenPos,totalCol);

            if(isSafe){
                
                 queenPos.push_back({row,i});

                nQueensALL(row+1,totalCol,queenPos);
               
                    queenPos.pop_back();
                
            }
    }

    if(!isSafe){
        //if current row is not safe
        return 0;
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

    // vector<vector<int>> maze = {
    //     {0,0,0},
    //     {0,0,0},
    //     {0,0,0}
    // };

    // vector<string> path;
    // mazePathWithBacktracking(0,0,"",path,maze);

    // for(auto str:path){
    //     cout<<str<<endl;
    // }
    vector<pair<int,int>> queenPos;
    // nQueen(0,4,4,queenPos);
    nQueensALL(0,4,queenPos);

    // for(int i=0; i<queenPos.size(); i++){
    //     cout<<"("<<queenPos[i].first<<","<<queenPos[i].second<<"), ";
    // }

}
