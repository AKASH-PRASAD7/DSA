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
         * @brief BFS Traversal- for connected nodes
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
void bfsDisconnected(map<int, vector<int>> graph){
    /**
         * @brief BFS Traversal- for all nodes (disconnected aswell)
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

   
            for(auto& node: graph){

                if (!visited.count(node.first))
                    {
                        nodes.push(node.first);
                        visited[node.first]=true;
                    }
                
                while(!nodes.empty()){

                    int current = nodes.front();
                    
                    cout<<current<<"->";
                    
                    nodes.pop();

                    for(int i=0; i<graph[current].size(); i++){

                        if(!visited.count(graph[current][i])){
                            nodes.push(graph[current][i]);
                            visited[graph[current][i]]=true;
                        }
                    }
                }
              
            }
}

void dfsTraversal(int &node,map<int, bool> &visited, map<int, vector<int>> &graph){
    

    cout<<node<<"->";

    for(int i=0; i<graph[node].size(); i++){

        if(!visited.count(graph[node][i])){
            visited[graph[node][i]]=true;
            dfsTraversal(graph[node][i],visited,graph);
        }
    }


}

void dfs(map<int, vector<int>> graph){
    /**
     * @brief DFS traversal
     * 
     * 1)Requorements- queue,visited
     * 
     * 2)loop through graph when find element mark push it in queue mark it as visited 
     * 3) loop thorugh it neighbor if neighbor not visited push it in queue and mark it as visited then recursive call through that source
     * 4) base condition node has no neighbors return;
     */

     map<int, bool> visited;
    
     int current;
     for(const auto& node: graph){
        if(!visited.count(node.first)){
           
            current= node.first;
            visited[node.first]=true;
            
            dfsTraversal(current,visited,graph);
        }
     }
}

void adjacencyListImplementation(vector<vector<int>> &edgeList){
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

    cout<<endl;

    bfsDisconnected(graphMap);
    cout<<"DFS"<<endl;
    dfs(graphMap);
}


int main(){
    /**
     * @brief Graph implementation undirected/bidirection
     *  
     * 1----2
     *  \ / |
     *   \  |   5--6
     *  /  \|
     * 4----3
     * 
     * input/given
     * 1) no of nodes and edgelist
     * 
     */

     vector<vector<int>> edgeList={{1,2},{1,3},{2,1},{2,3},{2,4},{4,2},{4,3},{5,6}};

     int nodes=7; //skipping 0

     //directed graph
    //  adjacencyMatrixImplementation(nodes,edgeList);
     cout<<endl;
     adjacencyListImplementation(edgeList);

      
}
