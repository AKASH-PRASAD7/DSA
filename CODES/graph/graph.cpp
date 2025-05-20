#include<iostream>
#include<vector>
#include<map>
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

void adjacencyListImplementation(vector<vector<int>> edgeList){
    /**
     * @brief 
     * 0) create a map of <int, arr,vector>
     * 1) map through edge list find from and to
     * 2) find if from alerady exist if yes push 'to' to its value
     * 3) if not create new entry
     * 
     */

     map<int, vector<int>> graphMap;

    for(int i=0; i<edgeList.size(); i++){

        int from = edgeList[i][0];
        int to = edgeList[i][1];

        graphMap[from].push_back(to);
    }

    for (auto it = graphMap.begin(); it != graphMap.end(); ++it) {
        cout << it->first << " -> ";
        for (int neighbor : it->second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

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

     vector<vector<int>> edgeList={{1,2},{1,3},{2,1},{2,3},{2,4},{4,2},{4,3}};

     int nodes=5; //skipping 0

     //directed graph
     adjacencyMatrixImplementation(nodes,edgeList);
     cout<<endl;
     adjacencyListImplementation(edgeList);

      
}