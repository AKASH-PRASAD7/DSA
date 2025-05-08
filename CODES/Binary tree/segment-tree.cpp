#include<iostream>
using namespace std;

class Node{
    public:
    int result;
    // int interval[1];
    int leftInterval;
    int rightInterval;
    Node* left;
    Node* right;

    public: 
        Node(int leftInterval=0,int rightInterval=0){
      
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

    Node* getRoot(){
        return this->root;
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

        //  this->root = new Node(0);
        // insertNodes(this->root,0,this->arraySize-1);

       this->root= generateTree(0,this->arraySize-1);
  

        //update query
        // this->root->query= this->root->left->query + this->root->right->query;
     }

     Node* generateTree(int leftInterval,int rightInterval){
        
        /**
         * @brief insertion logic
         * -> create new newnode with intervals as is params
         * -> find mid
         * -> create new node (left) with intervals(node->left,mid) (recursion call will return query)
         * -> create new node (right) with intervals(node->right,mid) (recursion call will return query)
         * -> return arr[leftinterval] if leftinterval == rightinterval
         * 
         * 
         */

        Node* newNode = new Node(leftInterval,rightInterval);
         
         int mid = (leftInterval+rightInterval)/2;

        if(leftInterval==rightInterval){
            newNode->leftInterval=leftInterval;
            newNode->rightInterval=rightInterval;

            newNode->result=this->array[leftInterval];

            return newNode;
        }
        
        //left
         newNode->left = generateTree(leftInterval,mid);

        //right
        newNode->right = generateTree(mid+1,rightInterval);

        newNode->result= newNode->left->result + newNode->right->result;

        return newNode;

 
     }


     int resultBetweenIterval(Node* node, int leftInterval,int rightInterval){
        /**
         * @brief Sum between intervals
         * Edge case
         * -> intervals outside range of nodeinterval return 0
         * -> if both intervals are in node return result
         * -> calculate mid of node
         * 
         * ->case 1 ans in left
         * -> if right interval is <= mid(node)
         * 
         * -> case 2 ans in right
         * -> if left interval >=maninclude 
         * 
         * ->case 3 ans overlapping
         * 
         * -> recursion leftinterval, mid(node) + recursion mid+1(node), right interval 
         */


         if(leftInterval>node->rightInterval || rightInterval< node->leftInterval){
            //outside range
            return 0;
         }

         if(leftInterval==node->leftInterval && rightInterval== node->rightInterval){
            //perfect macthing
            return node->result;
         }

         int mid=node->left->rightInterval;
         //result in left 
         if(rightInterval<=mid){
            return resultBetweenIterval(node->left,leftInterval,rightInterval);
         }

         //result in right
         if(leftInterval>=mid+1){
            return resultBetweenIterval(node->right,leftInterval,rightInterval);
         }

         //overlapping

        int leftResult= resultBetweenIterval(node->left,leftInterval,mid);
        int rightResult = resultBetweenIterval(node->right,mid+1,rightInterval);

        return leftResult+rightResult;

     }
    
     void inOrderTraversal(Node* node){
        /**
         * LNR
         * left->node(print)->right
         */

         if(node==nullptr){
            return;
         }

         inOrderTraversal(node->left);
         cout<<"->"<<node->result;
         inOrderTraversal(node->right);
    }
};

int main(){
    SegmentTree s;

    s.createTree();
    cout<<endl;
    s.inOrderTraversal(s.getRoot());
    cout<<endl;
   cout<<"result: "<<s.resultBetweenIterval(s.getRoot(),2,6);

}