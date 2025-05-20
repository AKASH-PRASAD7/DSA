#include<iostream>
#include<vector>
using namespace std;

void adjacencyMatrixImplementation(int nodes,vector<vector<int>> edgeList){
    vector<vector<int>> matrix(nodes, vector<int>(nodes,0));

    for(int i=0; i<edgeList.size(); i++){

        int from = edgeList[i][0];
        int to = edgeList[i][1];
        // cout << "Edge " << i << ": " << from << " -> " << to << endl;
        matrix[from][to]=1;
    }

    for(int i=0; i<nodes; i++){

        for(int j=0; j<nodes; j++){

            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void adjacencyListImplementation(int nodes,vector<vector<int>> edgeList){

}


int main(){
    /**
     * @brief Graph implementation undirected/bidirection
     *  
     * 1----2
     *  \ / |
     *   \  |
     *  /  \|
     * 4----3
     * 
     * input/given
     * 1) no of nodes and edgelist
     * 
     */

     vector<vector<int>> edgeList={{1,2},{1,3},{2,1},{2,3},{2,1},{2,4},{4,2},{4,3}};

     int nodes=5; //skipping 0

     adjacencyMatrixImplementation(nodes,edgeList);
     adjacencyListImplementation(nodes,edgeList);

      
}