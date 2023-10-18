#include<iostream>
#include<queue>
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


// BFS-breadth first search

void levelOrderTraversal(Node*root){
    
    if(root==nullptr){
        cout<<"Empty Tree !";
    }
    else
    {   
        queue<Node*>q1;
        q1.push(root);
        
        Node*curr;
        while(!q1.empty()){
            curr=q1.front();
            q1.pop();
            cout<<curr->data<<" ";
            
            //left of cuurent
            if(curr->left!=nullptr){
                q1.push(curr->left);
            }
             
             //right of cuurent
            if(curr->right!=nullptr){
                 q1.push(curr->right);
            }
            
        }
    }
}

Node insertBst(Node* root){
    int data=-1;
    cout<<"Enter data of root: ";
    cin>>data;
    if(!root){
        Node* newnode=new Node(data);
    }
}


int main(){
 
   return 0;
}