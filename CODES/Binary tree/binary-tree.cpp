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

void insert(Node* &root,int data){
    Node*newnode= new Node(data);
    if(root==nullptr){
        root=newnode;
    }
    else
    {
        queue<Node*>q1;
        q1.push(root);
        Node*curr;
        while(!q1.empty())
        {
            curr=q1.front();
            q1.pop();
            
            //checking for current node left
            if(curr->left==nullptr){
                curr->left=newnode;
                break;
            }
            //checking for current node right
            if(curr->right==nullptr){
                curr->right=newnode;
                break;
            }
            q1.push(curr->left);
            q1.push(curr->right);
        }

    }
} 





void inorderTraversal(Node*root){
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

int main(){
  Node* root=nullptr;
 insert(root,1);
 insert(root,2);
 insert(root,3);
 insert(root,4);
 insert(root,5);
 insert(root,6);
 insert(root,7);
    inorderTraversal(root);
   return 0;
}