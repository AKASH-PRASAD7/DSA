#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        int height;
        Node* left;
        Node* right;

        Node(int data){
            this->data=data;
            this->left=nullptr;
            this->right=nullptr;
        }

};
//1st simple implementation
void printTree(Node* root){
    if(root==nullptr){
        cout<<"Empty tree";
    }else{
        cout<<root->data<<endl;
        cout<<root->left->data;
        cout<<root->right->data;
    }
}

Node* createSimpleBtree(){
    int data=0;
    cout<<"Enter root: ";
    cin>>data;
    Node* root=new Node(data);

    cout<<endl<<"Enter "<<root->data<<" of left: ";
    cin>>data;
    Node* left=new Node(data);
    root->left=left;
    
    cout<<endl<<"Enter "<<root->data<<" of right: ";
    cin>>data;
    Node* right=new Node(data);
    root->right=right;

    return root;
}

class BST {
    Node* root;

    public:
        BST(){
            this->root=nullptr;
        }
    
    Node* getRoot(){
        return this->root;
    }

    void insert(){
        int rootVal;
        cout<<"Enter root: ";
        cin>>rootVal;
        this->root=new Node(rootVal);

        int data;

        while(true){
        
        cout<<endl<<"ENTER DATA: ";
        cin>>data;
        if(data==-1){
            break;
        } 
        insertNode(this->root,data);
        }


    }

    void insertNode(Node* node,int data){
      
            if(data<node->data){
                //if smaller then current node insert at left
                if(node->left==nullptr){
                //if nothing at left then just insert else check its left
                Node* newNode=new Node(data);
                node->left=newNode;
                cout<<endl<<"inserted "<<data<<" at left of "<<node->data<<endl;

                }
                else{
                    insertNode(node->left, data);
                }
            }
            else{
                if(node->right==nullptr){
                    //if nothing at right then just insert else check its right
                    Node* newNode=new Node(data);
                    node->right=newNode;
                    cout<<endl<<"inserted "<<data<<" at right of "<<node->data<<endl;
                    }
                    else{
                        insertNode(node->right, data);
                    }
            }
        }

    
    void printNode(Node* root){
            
        if(root==nullptr){
            return;
        }

        cout<<root->data;

        //left            
        printNode(root->left);

        //right
        printNode(root->right);
    }

    void printTree(){
        if(this->root==nullptr){
            cout<<"Empty tree!";
        }else{
            
            // printNode(this->root);
            // prettyPrint(this->root,1);
        }
    }

    void bfs(){
        /**
         * @brief BFS
         *           1
         *         /   \
         *        2     3
         *      /  \   / \
         *    4    5  6   7
         * 
         * 
         * 1)
         * 3) 
         * 
         */
        queue <Node*> q1; 

        q1.push(this->root);

        while(!q1.empty()){
            cout<<q1.front()->data<<"->";
            // Only push non-null children
            if (q1.front()->left != nullptr) {
                q1.push(q1.front()->left);
            }
            if (q1.front()->right != nullptr) {
                q1.push(q1.front()->right);
            }

            q1.pop();
        }
            
    }



};



        

        






int main(){
    // Node* root=createSimpleBtree();
    // printTree(root);

    BST b;

    b.insert();
    
    cout<<endl;
    b.bfs();
    cout<<endl;



    return 1;
}