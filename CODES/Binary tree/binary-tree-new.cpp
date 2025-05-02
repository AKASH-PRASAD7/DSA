#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }

};

class BTree{
    private:
      Node* root;
    
    public:
        BTree(){
            this->root=nullptr;
        }      

        void insertNode(Node* currNode){
            //lnr insertion
            int data=0;
            cout<<"Enter data to insert at left of "<<currNode->data<<endl;
            cin>>data;

        }
        
};