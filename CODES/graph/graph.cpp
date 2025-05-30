#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include <utility>
#include <climits>
#include <unordered_map>
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

bool bfsCycle(int node,map<int, vector<int>> &graph,map<int, bool> &visited){
    
    
    queue<int> nodes;
     map<int,int> parent;

     nodes.push(node);
     visited[node]=true;
     parent[node]=-1;

     while(!nodes.empty()){
        int current= nodes.front();
        nodes.pop();

        for(int neighbor: graph[current]){
            
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    parent[neighbor]=current;
                    nodes.push(neighbor);
                }else if( parent[current]!=neighbor){
         
                    return true;
                }
            
        }


     }


    return false;
}

void cycleDetectionBFS(vector<vector<int>> &edgeList){
    //create adjacency graph

    map<int, vector<int>> graph;

    for(int i=0; i<edgeList.size(); i++){

        int first = edgeList[i][0];
        int second = edgeList[i][1];

        //undirected
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    for(const auto& node: graph){
        cout<<node.first<<"->";
        for(int i=0; i<node.second.size();i++){
            cout<<node.second[i]<<" ,";
        }
            cout<<endl;
    }

    /**
     * @brief cycle detection
     * 
     * 1) same as bfs traversal
     * 2) need one data structure to keep track of parent
     * 3) cycle condition if node if visited and it not equal to cuurent parrent
     * 
     */

     map<int, bool> visited;

     bool cycle=false;

     for(const auto& node: graph){

            if(!visited[node.first]){

                cycle= bfsCycle(node.first,graph,visited);
            }

           if(cycle){
            cout<<"cycle detected";
            return;
            
           }
        
     }

     if(!cycle){
        cout<<"no cycle";
     }

}


bool dfsCycle(int node,map<int,bool> &visited,int par, map<int, vector<int>> &graph){

    
   
    visited[node]=true;
   

    for(auto neighbour: graph[node]){
        if(!visited[neighbour]){

            
            if(dfsCycle(neighbour,visited,node,graph)){
                return true;
            }
        }else if(neighbour!=par){
            return true;
        }
    }

    return false;
}

void dfsCycleDetect(vector<vector<int>> edgeList){
    //create adjacency graph

    map<int, vector<int>> graph;

    for(int i=0; i<edgeList.size(); i++){

        int first = edgeList[i][0];
        int second = edgeList[i][1];

        //undirected
        graph[first].push_back(second);
        graph[second].push_back(first);
    }

    for(const auto& node: graph){
        cout<<node.first<<"->";
        for(int i=0; i<node.second.size();i++){
            cout<<node.second[i]<<" ,";
        }
            cout<<endl;
    }

    /**
     * @brief cycle detection
     * 
     * 1) same as dfs traversal
     * 2) need one data structure to keep track of parent
     * 3) cycle condition if node if visited and it not equal to cuurent parrent
     * 
     */


     map<int,bool>visited;
    bool cycle=false;

    int par=-1;

     for(const auto& node:graph){
        if(!visited.count(node.first)){

         

            cycle = dfsCycle(node.first,visited,par,graph);
            if(cycle){
                cout<<"cycle detected";
                return;
            }

        }
     }

     cout<<"no cycle";
}

bool dfsCycle(int source,map<int,bool> &visited,map<int,bool> &dfs, map<int,vector<int>> &graph ){
    visited[source]=true;
    dfs[source]=true;
   

    for(const auto& neighbour: graph[source]){
        if(!visited[neighbour]){
            if(dfsCycle(neighbour,visited,dfs,graph))
                {
                    return true;
                }
        }else if(dfs[neighbour]){
            return true;
        }
    }
    dfs[source]=false;
    return false;
}

void dfsDetectDirected(vector<vector<int>> &edgeList){
    /**
     * @brief Undirected dfs cycle detect
     * 
     *       1 → 2 → 3 → 7
                ↓    ↘  ↑
                4      8 
               ↓  ↑
              5 → 6 

     * 
        1) requirement dfs trackers
        2) do normal dfs but with every dfs call store it
        3) if visited and dfsmarked are true then cycle present
     */

     //graph
     map<int,vector<int>> graph;

     for(int i=0; i<edgeList.size(); i++){
        int from = edgeList[i][0];
        int to = edgeList[i][1];

        graph[from].push_back(to);
     }



     map<int,bool>visited;
     map<int,bool>dfs;

     for(const auto& node: graph){
        if(!visited.count(node.first)){

            if(dfsCycle(node.first,visited,dfs,graph)){
                cout<<"cycle detected";
                return;
            }
        }
     }

     cout<<"no cycle detected";
}

void dfsToplogical(int node,vector<int> &visited,stack<int> &sort,map<int, vector<int>> &graph ){
    visited[node]=1;

    for(const auto& neighbour: graph[node]){
        if(!visited[neighbour]){
            dfsToplogical(neighbour,visited,sort,graph);
        }
    }

    sort.push(node);

} 

void toplogicalSort(vector<vector<int>> &edgeList){
    //graph creation

    map<int, vector<int>> graph;

    for(int i=0; i<edgeList.size(); i++){
        int from = edgeList[i][0];
        int to = edgeList[i][1];

        graph[from].push_back(to);
    }

    /**
     * @brief Topolgical sort- it folows a order 
     * eg. if 3->2,1
     * then 3 should come first for valid topological sort- >3 ,2, 1
     * 
     * 1)normal dfs algo and for node with no dfs call remaining push it into stack
     * 
     */


    vector<int> visited(20,0); //adjust according to no of nodes
    stack<int> sort;

    for(const auto& node: graph){
        if(!visited[node.first]){
            dfsToplogical(node.first,visited,sort,graph);
        }
    }

    while(!sort.empty()){
        cout<<sort.top()<<"->";
        sort.pop();
    }
    
}




void topologicalSortBfs(vector<vector<int>> &edgeList){
    /**
         * @brief Topological Sort using BFS (Kahn's Algorithm)
         * 
         * Step-by-step:
         * 
         * 1. Build the graph using an adjacency list.
         * 2. Create an 'indegree' array/map to count how many edges point into each node.
         * 3. Loop through the indegree map:
         *    - Push all nodes with indegree 0 into a queue (they have no dependencies).
         * 
         * 4. While the queue is not empty:
         *    - Pop a node from the front of the queue.
         *    - Add it to the result (topological order).
         *    - For each neighbor of this node:
         *        - Decrease its indegree by 1.
         *        - If its indegree becomes 0, push it into the queue.
         * 
         * 5. After the loop, the result list will contain the topological order.
         *    - If the result doesn't contain all nodes, a cycle exists in the graph.
         * 
    */


    //graph create

    map<int, vector<int>> graph;

    vector<int> indegree(20); //adjsust according to node size

    for(int i=0; i<edgeList.size(); i++){
        int from=edgeList[i][0];
        int to=edgeList[i][1];

        graph[from].push_back(to);

        //implementing indegree 
        indegree[to]++;
    }

   

    queue<int> nodes;
    vector<int> topologicalSort;

    for(const auto& node: graph){
        if(indegree[node.first]==0){
            nodes.push(node.first);
        }
    }
            while(!nodes.empty()){
                int front=nodes.front();
                nodes.pop();
                topologicalSort.push_back(front);

                for(auto& neighbour: graph[front]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        nodes.push(neighbour);
                    }
                }
            }
        //check for cycle
        if (topologicalSort.size() != indegree.size()) {
                cout << "Cycle detected or incomplete graph." << endl;
                return;
        }

   for(int i=0; i<topologicalSort.size(); i++){
        cout<<topologicalSort[i]<<"->";
   }

}


void shortTestPathBFS(int source, int destination,vector<vector<int>> &edgeList){
    /**
     * @brief Shortest path in graph algo 
     * - BFS algo with a parent node tracker
     * - After all node visited, backtrack from destination with parent nodes DS
     * 
     */

     //graph

     map<int, vector<int>> graph;

     for(int i=0; i<edgeList.size(); i++){
        int from = edgeList[i][0];
        int to = edgeList[i][1];

        graph[from].push_back(to);
        graph[to].push_back(from);
     }

     map<int,bool> visited;
     map<int,int> parent;
     queue<int> nodes;

     

            nodes.push(source);
            parent[source]= -1;

            while (!nodes.empty())
            {   
                int front = nodes.front();
                visited[front]=true;
                nodes.pop();

                for(auto& neighbour: graph[front]){
                    if(!visited[neighbour]){
                        visited[neighbour]=true;
                        parent[neighbour]=front;
                        nodes.push(neighbour);
                    }
                }
            }
            
      
    
    int ptr=destination;

     while(ptr!=source){
        if(ptr==destination){
            cout<<destination<<"<-";
        }
        cout<<parent[ptr]<<"<-";
        ptr=parent[ptr];
     }
}

void dfsShortestPath(int source,map<int,bool> &visited,stack<int> &topologicalSort,map<int,vector<pair<int,int>>> &graph){
    visited[source]=true;

    for(auto& neighbour: graph[source]){
        if(!visited[neighbour.first]){
            dfsShortestPath(neighbour.first,visited,topologicalSort,graph);
        }
    }

    topologicalSort.push(source);
}

void shortesPathInWeightedGraph(int source,int destination,vector<vector<int>> &edgeList){
    /**
     * @brief Shortest path in directed acyclic weighted graph
     * 
     * 1) find toplogical sort
     * 2) with help of topological sort find shortest path from source to all nodes
     * 3) initailize with infinty at first, for source it will be 0
     */

     //graph

     map<int,vector<pair<int,int>>> graph;

     for(int i=0; i<edgeList.size(); i++){
        int from = edgeList[i][0];
        int to = edgeList[i][1];
        int weight = edgeList[i][2];

        graph[from].push_back({to,weight});
     }


     map<int,bool> visited;
     stack<int> topologicalSort;

    dfsShortestPath(source,visited,topologicalSort,graph);

 
   vector<int> distance(6,INT16_MAX); //adjust accroding to no of node

    //setting source 0
   distance[source]=0;

   while(!topologicalSort.empty()){

        if(distance[topologicalSort.top()]==INT16_MAX){
            //if distance infinity then pop
            topologicalSort.pop();
        }else{
            int current=topologicalSort.top();

            for(auto& neighbour: graph[current]){
                //update distance only if its less
                if(distance[neighbour.first]> distance[current] +neighbour.second){
                    distance[neighbour.first] = distance[current] +neighbour.second;
                }
            }
            topologicalSort.pop();
        }
   }

   for(int i=0; i<distance.size(); i++){
     cout<<distance[i]<<", ";
   }
}


void dijkstra(int source,int destination,vector<vector<int>> &edgeList){
    /**
     * @brief Dijkstra algo
     * - reuirement pripority queue to  store (dist,node)
     * 
     * 1) start from source node mark source node distance 0
     * 2) traverse its neighbour like BFS 
     * 3) if dist of source to neigh+ source dist < neighb distance
     * 4) then update distance of neighbour and psuh push
     * 5) rpeat 
     * 
     * 
     * 
     */


     //graph

     map<int,vector<vector<int>>> graph;

     for(int i=0; i<edgeList.size(); i++){
        int from = edgeList[i][0];
        int to = edgeList[i][1];
        int dist = edgeList[i][2];

        //undirected

        graph[from].push_back({to,dist});
        graph[to].push_back({from,dist});
     }

     priority_queue
    <
    pair<int,int>,                     // Type of elements (here: pair of {distance, node})
    vector<pair<int,int>>,            // Underlying container (default is vector)
    greater<pair<int,int>>            // Comparison function (min-heap instead of max-heap)
    > 
    nodes;

     vector<int> distance(20,INT_MAX); //addjust according to no of nodes;

     //set source dist 0
     distance[source]=0;


     // dist,node
     nodes.push({0,source});

     while(!nodes.empty()){
        int currNode = nodes.top().second;
        int currDist = nodes.top().first;

        nodes.pop();

        if (currDist > distance[currNode]) {
            //skipping for efficinecy
            continue;
        }

        for(const auto& neighbour: graph[currNode]){
            int neighbourNode = neighbour[0];
            int neighbourDist = neighbour[1];
            
            //check if distance more
            if(distance[neighbourNode]> currDist+neighbourDist){
                distance[neighbourNode]=currDist+neighbourDist;

                nodes.push({distance[neighbourNode],neighbourNode});

            }
        }
     }


     for(int i=source;i<=destination;i++){
        cout<<distance[i]<<", ";
     }
    

}


void primsAlgo(int source,vector<vector<int>> &edgeList){
    /**
     * @brief Prims algo used to find MST (minimum spanning tree)
     * 
     * 1) a min heap (priority queue) storing (weight,node,parent), 
     * mst array storing edges , visited DS for nodes and a sum of mst weights 
     * 
     * 2) start from any node push it to queue with parent -1
     * 3) start loop while queue not empty
     * 4) if parent is -1 dont push it to MST, otherwise push current (node,parent) and weights to sum
     * 5) mark current node visited and iterate over curr nodes neighbour
     * 6) if neighbour unvisited push them to queue (weight-from-current-neeightbor,neighbour,current)
     * 7) done
     * 
     */

     //graph adjaceny list creation

     unordered_map<int,vector<vector<int>>> graph;

     for(int i=0; i<edgeList.size(); i++){
        int from = edgeList[i][0];
        int to = edgeList[i][1];
        int weight = edgeList[i][2];

        //undirected
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
     }

     int mstSum = 0;
     priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> nodes;
     unordered_map<int,bool> visited;
     vector<pair<int,int>> mst;

     //push source (weight,node,parent)
     nodes.push({0,0,-1});

     while (!nodes.empty())
     {
        int topNode = nodes.top()[1];
        int weight = nodes.top()[0];
        int parent = nodes.top()[2];

        if(visited[topNode]){
            //skip if visited
            nodes.pop();
        }else{

            //mark current node visted
            visited[topNode]=true;

            if(parent!=-1){
                //push into mst and update sum only when there is parent
                mst.push_back({parent,topNode});
                mstSum += weight;
            }

            //traverse neighbours
            for(auto & neighbour: graph[topNode]){
                int neighBourNode = neighbour[0];
                int neighBourWeight = neighbour[1];

                if(!visited[neighBourNode]){
                    nodes.push({neighBourWeight,neighBourNode,topNode});
                }
            }
        }
     }

     cout<<mstSum<<endl;

     for (auto& edge : mst) {
        cout << edge.first << " - " << edge.second << endl;
    }
     
    
}

class DisjointSet{
    /**
     * @brief Disjoint set (used to tell that if two nodes are of same component or not)
     * 
     * - requirement a parent and rank or size array/vector
     * 
     * 1) initialize ranks of all node by 0/-1, and parent as themselves 
     *  - if size assign all size as 1
     * 2) (unionbyrank) take first two nodes set if both have same rank attach one to another or vices verse
     *  and icrement rank of parent if ones rank is bigger then attach smaller to bigger, and mark parent 
     *  accordingly in both cases
     * 
     *  (unionbysize) take first two nodes set if both have same size attach one to another or vices verse
     *   if ones size is bigger then attach smaller to bigger, and mark parent accordingly in
     *      both cases and update size of parent as + attched size
     * 
     * 3) repeat this for all ndoes set
     * 
     * 4) create a find utlimate parent function that returns ultimate parent of node
     *  and also updates its, and it also does path compression by changing other nodes
     *  parents aswell in process (backtracking)
     * 
     *  e.g--> 1->2->3->4 for ultimate parent of 1  it will return 1 and update others parents also
     *          in process 1->4<-3   
     *                       / 
     *                      2     
     * 
     * 5) if two nodes have same ultimate parent then they are in same component
     */ 
    
     
    vector<int> rank, size, parent;

    public:
        DisjointSet(int nodes){
            //intilaization
            rank.resize(nodes+1,0);
            size.resize(nodes+1,1);
            parent.resize(nodes+1);
            for(int i=1; i<=nodes;i++){
                parent[i]=i;
            }
        }
        int getParent(int node){
            
            //ultimate parent

            if(node==parent[node]){
                return node;
            }
            //updates parents and path compression
           return parent[node]=getParent(parent[node]);
       }

       bool isSameComponent(int node1, int node2){
         return getParent(node1) == getParent(node2);
       }

       void unionByRank(int node1,int node2){
            //if both are already in same comp then return
            int parent1 = getParent(node1);
            int parent2 = getParent(node2);
        
            if (parent1 == parent2) return;
        
            if (rank[parent1] > rank[parent2]) {
                parent[parent2] = parent1;
            } else if (rank[parent2] > rank[parent1]) {
                parent[parent1] = parent2;
            } else {
                parent[parent2] = parent1;
                rank[parent1]++;
            }
       }
       void unionBySize(int node1,int node2){
            //if both are already in same comp then return
            int parent1 = getParent(node1);
            int parent2 = getParent(node2);
        
            if(parent1 == parent2) return;
        
            if(size[parent1] > size[parent2]) {
                parent[parent2] = parent1;
                size[parent1] += size[parent2];
            } else {
                parent[parent1] = parent2;
                size[parent2] += size[parent1];
            }
       }
};

void krushkalsAlgo(int nodes,vector<vector<int>> &edgelist){
    /**
     * @brief Kruskalalgo to find MST
     * 
     * - requirement disjoint set DS and a sorted DS(priority queue) of item (weight,nodefrom, nodeto)
     * 
     * 1) Get top from queue
     * 2) check if its in same component
     * 3) if not union them otherwise skip
     * 4) update the mst sum and repeat
     */

    //graph
    unordered_map<int,vector<vector<int>>> graph;
    priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> edgeWeights;

    for(int i=0; i<edgelist.size(); i++){
        int from =  edgelist[i][0];
        int to =  edgelist[i][1];
        int weight =  edgelist[i][2];

        
        graph[from].push_back({to,weight});

        //push in edgequeue (weight,nodefrom, nodeto)
        edgeWeights.push({weight,from,to});
        
    }

    //initialize disjoint set
    DisjointSet s(nodes);
    int mstSum = 0;

    while(!edgeWeights.empty()){
        int from = edgeWeights.top()[1];
        int to = edgeWeights.top()[2];
        int weight = edgeWeights.top()[0];

        if(!s.isSameComponent(from,to)){
            s.unionBySize(from,to);
            mstSum += weight;
        }
        edgeWeights.pop();
    }
    

    cout<<mstSum;
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

     //disjoint set

    //  DisjointSet set(7);

    //  set.unionBySize(1,2);
    //  set.unionBySize(2,3);
    //  set.unionBySize(4,5);
    //  set.unionBySize(6,7);
    //  set.unionBySize(5,6);
    //  cout<<set.isSameComponent(3,7)<<endl;
    //  set.unionBySize(3,7);
    //  cout<<set.isSameComponent(3,7)<<endl;

     vector<vector<int>> edgeList = {
        {0, 1, 4},
        {0, 2, 1},
        {2, 1, 2},
        {1, 3, 1},
        {2, 3, 5},
        {3, 4, 3}
    };
    
    //  vector<vector<int>> edgeList={{1,2},{1,3},{1,4},{2,1},{2,5},{3,1},{3,8},{4,1},{4,6},{5,2},{5,8},{6,4},{6,7}
    // ,{7,6},{7,8},{8,3},{8,5},{8,7}
    // };
    //  vector<vector<int>> edgeList={{1,2},{1,3},{2,5},{3,5},{5,4}};
    //  vector<vector<int>> edgeList={{1,2},{2,3},{2,4},{3,7},{3,8},{4,5},{5,6},{6,4},{8,7}};
    //  vector<vector<int>> edgeList={{1,2},{1,3},{2,3},{2,4},{4,3},{5,6}};
    // vector<vector<int>> edgeList = {
    //     {1, 2},
    //     {1, 3},
    //     {3, 4},
    //     {5, 6}
    // };

     int nodes=7; //skipping 0

     //directed graph
    //  adjacencyMatrixImplementation(nodes,edgeList);
     cout<<endl;
    //  adjacencyListImplementation(edgeList);

    // cycleDetectionBFS(edgeList);
    // dfsCycleDetect(edgeList);

    // dfsDetectDirected(edgeList);

    // toplogicalSort(edgeList);

    // topologicalSortBfs(edgeList);
    // shortTestPathBFS(1,8,edgeList);

    // shortesPathInWeightedGraph(1,5,edgeList);
    // dijkstra(1,4,edgeList);
    primsAlgo(1,edgeList);
    krushkalsAlgo(5,edgeList);
}
