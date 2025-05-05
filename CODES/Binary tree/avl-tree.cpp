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
            insertNode(this->root,data);
        }
    }

    Node* getRoot(){
        return this->root;
    }

    Node* insertNode(Node* node,int data){

        if(node==nullptr){
            Node* newNode=new Node(data);
            return newNode;
        }

        if(data<node->data){

            if(node->left==nullptr){

            node->left=insertNode(node->left,data);
            node->height++;
            cout<<endl<<data<<" inserted at left of "<<node->data;

            }
            else{

                insertNode(node->left,data);
            }
        }else if (data > node->data){

            if(node->right==nullptr){

            node->right=insertNode(node->right,data);
            cout<<endl<<data<<" inserted at right of "<<node->data;

            }
            else{
                insertNode(node->right,data);
            }

        }else{
            return node;
        }

        node->height=max(getHeight(node->left),getHeight(node->right))+1;
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