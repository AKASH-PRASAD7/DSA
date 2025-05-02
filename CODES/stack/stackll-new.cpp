#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class Stack{
    private:
    Node* top;

    public:
    Stack(){
        this->top=nullptr;
    }

    void push(int data){
        Node *newNode=new Node(data);
        if(this->top==nullptr){
            this->top=newNode;
        }else
        {
          newNode->next=this->top;
          this->top=newNode;
        }
    }

    void pop(){
        Node *deleteNode=this->top;
        //empty stack
        if(this->top==nullptr){
            cout<<"Stack underflow";
        }else{
            this->top=deleteNode->next;
        }
        cout<<"Popped!"<<endl;
        delete deleteNode;
        deleteNode=nullptr;
    }

    void traverse(){
        Node*ptr=this->top;
        int i=1;
        if(ptr==nullptr){
            cout<<"Empty stack!";
        }else{
        while(ptr!=nullptr){
            cout<<" Node:("<<i++<<") "<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }
    }

    void stackTop(){
        if(this->top==nullptr){
            cout<<"stack underflow!";
        }else{
            cout<<"stack top: "<<this->top->data;
        }
    }
};


int main(){

    
       Stack l;
       bool exit =false;
       int action=0;
       int data=0;
       int updatedData=0;
    
    
       while(!exit){
        cout<<endl<<"(1) for insertion"<<endl<<"(2) for deletion"<<endl<<"(3) to  traverse forward"<<endl<<"(4) to print top"<<endl<<"(5) to exit"<<endl;
        cout<<"Enter: ";
        cin>>action;
    
        switch(action){
            case 1:
            cout<<"Enter data to insert: ";
            cin>>data;
            l.push(data);
            break;
    
            case 2:
            l.pop();
            break;
    
            case 3:
            l.traverse();
            break;
    
            case 4:
            l.stackTop();
            break;
    
            case 5:
            exit=true;
            break;
    
            default:
            cout<<"Invalid input";
        }
    
       }
    

    
        
    
        return 0;
    }