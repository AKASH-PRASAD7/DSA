#include<iostream>
#include <algorithm> 
using namespace std;
class Node{
    public:
        int data;
        int height;
        Node* left;
        Node* right;
    
    public:
        Node(int data){
            this->data=data;
            this->height=0;
            this->left=this->right=nullptr;
        }
};

class AVLTree{
    private:
     Node* root;
    
    public:
     AVLTree(){
        this->root=nullptr;
     }
    
    int getHeight(Node* node){
        return node==nullptr?-1:node->height;
    }

    int getBalanceFactor(Node* node){
        return node==nullptr?0: getHeight(node->left)-getHeight(node->right);
    }
    
    void insert(){
        int data;
        cout<<"Enter data to be inserted at root: ";
        cin>>data;
        this->root=new Node(data);

        while(true){
            cout<<endl<<"Enter data to be inserted at root: ";
            cin>>data;
            if(data==-1){
                //considering -1 for null
                break;
            }
           this->root= insertNode(this->root,data);
        }
    }

    Node* getRoot(){
        return this->root;
    }

    Node* leftRotate(Node* node){
        /**
         * @brief left rotate
         *        
         *        p                                    c
         *      /  \      left rotate P              /  \
         *     t1   c      ----------------->       p    t3
         *         /  \                            / \
         *       t2   t3                          t1  t2
         */

        Node* c=node->right;
        Node* t2= node->right->left;
     
        node->right=t2;
        c->left=node;

        //update height
        node->height= max(getHeight(node->left),getHeight(node->right))+1;
        c->height= max(getHeight(c->left),getHeight(c->right))+1;

        return c;
    }

    Node* rightRotate(Node* node){
        /**
         * @brief right rotate
         *        
         *        p                                    c
         *      /  \      right rotatate P           /  \
         *     c    t3   ----------------->         t1   p
         *   /  \                                       / \
         *  t1  t2                                    t2   t3
         */

         Node* c=node->left;
         Node* t2= node->left->right;
      
         node->left=t2;
         c->right=node;
        
         //update height
        node->height= max(getHeight(node->left),getHeight(node->right))+1;
        c->height= max(getHeight(c->left),getHeight(c->right))+1;

         return c;
        
    }


    Node* avlCheck(Node* node){

        int balance = getBalanceFactor(node);

    // Left-Left (LL) Case
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rightRotate(node);
    }

    // Left-Right (LR) Case
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Right (RR) Case
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return leftRotate(node);
    }

    // Right-Left (RL) Case
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
    }

    Node* insertNode(Node* node,int data){

        if(node==nullptr){
            Node* newNode=new Node(data);
            return newNode;
        }

        if(data<node->data){
            node->left=insertNode(node->left,data);
            
        }
        else if(data>node->data){
            node->right=insertNode(node->right,data);
            
        }else {
            
        return node;
        }

        node->height=max(getHeight(node->left),getHeight(node->right))+1;

        return avlCheck(node);
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
         cout<<"->"<<node->data;
         inOrderTraversal(node->right);
    }

    void preOrderTraversal(Node* node){
        /**
         * NLR
         * node(print)->left->right
         */

         if(node==nullptr){
            return;
         }

         cout<<"->"<<node->data;
         preOrderTraversal(node->left);
         preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node){
        /**
         * LRN
         * left->right->node(print)
         */

         if(node==nullptr){
            return;
         }

         postOrderTraversal(node->left);
         postOrderTraversal(node->right);
         cout<<"->"<<node->data;
    }


};

int main(){

    AVLTree t;

    t.insert();
    cout<<endl;
    t.inOrderTraversal(t.getRoot());
    cout<<endl;
    cout<<"height: "<<t.getHeight(t.getRoot());
    cout<<endl;
    cout<<"Balance factor: "<<t.getBalanceFactor(t.getRoot());
}