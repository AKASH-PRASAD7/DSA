#include<iostream>
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

//2nd actual implementaion
class BTree{
    private:
      Node* root;
    
    public:
        BTree(){
            this->root=nullptr;
        }      

        void insertNode(Node* root){
            //lnr insertion
            // considering -1 input as null
            int data;            
            //left
            cout<<endl<<"Enter left of "<<root->data<<"  :";
            cin>>data;
            if(data!=-1){
                Node* leftNode=new Node(data);
                root->left=leftNode;
                insertNode(leftNode);
            }
            //right
            cout<<endl<<"Enter right of "<<root->data<<"  :";
            cin>>data;
            if(data!=-1){
                Node* rightNode=new Node(data);
                root->right=rightNode;
                insertNode(rightNode);
            }
        }

        void createTree(){
            int rootVal;
            cout<<"Enter root: ";
            cin>>rootVal;
            this->root=new Node(rootVal);
            insertNode(root);
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

        void prettyPrint(Node* node,int level){
            /**
             *    
             *   |-->9
             *   |
             * 15|    |->14
             *   |    |
             *   |-->6|
             *        |   |->10
             *        |->8|
             * 
             * 
             * 5
             * 34
             * 
             */
          

             if(node==nullptr){
                return;
             }

            //(print right first) go to right
            prettyPrint(node->right,level+1); //5 
            if(level==1){
                cout<<endl<<"|"<<endl<<"|";
            }else{
                cout<<"|";
             for(int i=0;i<=level;i++){
                cout<<"-";
                if(i==level){
                    cout<<">";
                }
             }
            }
            cout<<node->data;
             prettyPrint(node->left,level+1);

        }
        
        void printTree(){
            if(this->root==nullptr){
                cout<<"Empty tree!";
            }else{
                
                // printNode(this->root);
                prettyPrint(this->root,1);
            }
        }


        
};


class BST :public BTree{
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
            prettyPrint(this->root,1);
        }
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
    // Node* root=createSimpleBtree();
    // printTree(root);

    // BTree b;
    BST b;

    b.insert();
    b.printTree();
    cout<<endl;
    b.inOrderTraversal(b.getRoot());
    cout<<endl;
    b.preOrderTraversal(b.getRoot());
    cout<<endl;
    b.postOrderTraversal(b.getRoot());
    cout<<endl;



    return 1;
}