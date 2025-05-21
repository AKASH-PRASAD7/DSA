#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

void bfs(int source,map<int, vector<int>> graph){
    /**
         * @brief BFS Traversal
         * 
         * 1) Requirements:
         *    - A queue to keep track of nodes to visit next.
         *    - A map (or set) to track visited nodes.
         * 
         * 2) Loop through all nodes in the graph (to handle disconnected components).
         * 
         * 3) If the node is not visited:
         *    a) Push the node into the queue.
         *    b) Mark it as visited.
         * 
         * 4) While the queue is not empty:
         *    a) Pop the front node.
         *    b) Process it (e.g., print it).
         *    c) For each neighbor of this node:
         *        - If it's not visited:
         *            - Push it into the queue.
         *            - Mark as visited.
         * 
    */

     queue<int> nodes;
     map<int,bool> visited;

     nodes.push(source);
     visited[source]=true;

     while(!nodes.empty()){

        cout<<nodes.front()<<"->";

        for(int i=0; i<graph[nodes.front()].size(); i++){
      
         
            if(!visited[graph[nodes.front()][i]]){
                //not visited
                nodes.push(graph[nodes.front()][i]);

                //then mark as visited
                visited[graph[nodes.front()][i]]=true;
            }

        }
        //pop the visited one
        nodes.pop();

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

    for (auto& node : graphMap) {
        cout << node.first << "  -> ";
        for (int neighbor : node.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    //source it one
    bfs(1,graphMap);

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
    //  adjacencyMatrixImplementation(nodes,edgeList);
     cout<<endl;
     adjacencyListImplementation(edgeList);

      
}
