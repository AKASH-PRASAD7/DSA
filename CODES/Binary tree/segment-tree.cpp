#include<iostream>
using namespace std;

class Node{
    public:
    int query;
    // int interval[1];
    int leftInterval;
    int rightInterval;
    Node* left;
    Node* right;

    public: 
        Node(int query,int leftInterval=0,int rightInterval=0){
            this->query=query;
            this->left=this->right=nullptr;
            this->leftInterval=leftInterval;
            this->rightInterval=rightInterval;
            // this->interval[0]=leftInterval;
            // this->interval[1]=rightInterval;
        }
    
    

};

/**
 * @brief Segement tree
 * 
 * 
 */

class SegmentTree{
    int *array;
    int arraySize;
    Node* root;

    public:
     SegmentTree(){
        this->root=nullptr;
     }

    void createTree(){
        cout<<"Enter size of array: ";
        cin>>this->arraySize;

        this->array= new int[this->arraySize];

        

        for(int i=0; i<this->arraySize; i++){
            cout<<endl<<"Enter ("<<i<<") element: ";
            cin>>this->array[i];
        }

        /**
         * @brief Intializing root
         *  query value will be empty at first, it will return after compeltion of tree
         */

         this->root = new Node(0);
        insertNodes(this->root,0,this->arraySize-1);

        //update query
        this->root->query= this->root->left->query + this->root->right->query;
     }

     Node* insertNodes(Node* node,int leftInterval,int rightInterval){

        /**
         * @brief insertion logic
         * -> mid mid of node
         * -> create new node (left) with intervals(node->left,mid) (recursion call will return query)
         * -> create new node (right) with intervals(node->right,mid) (recursion call will return query)
         * -> return arr[leftinterval] if leftinterval == rightinterval
         * 
         * 
         */

         if(leftInterval==rightInterval){
            // Node

            Node * newNode = new Node(this->array[leftInterval],leftInterval,rightInterval);
            return newNode;
         }

         //left
         node->left=insertNodes(node->left,leftInterval,(leftInterval+rightInterval)/2);

        // right
        node->right=insertNodes(node->right,((leftInterval+rightInterval)/2)+1,rightInterval);

     }
    
    
};