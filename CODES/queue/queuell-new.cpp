#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }

    Node(){
        this->next=nullptr;
    }
};

class Queue{
    private:
    Node* front;
    Node* back;
    int size;

    public: 
    Queue(){
        this->size=0;
        this->front=nullptr;
        this->back=nullptr;     
    }
    int isEmpty(){
        if(this->size<=0){
            return 1;
        }else{
            return 0;
        }
        return -1;
    }
    void printFront(){
        if(this->isEmpty()){
            cout<<"Empty queue!";
        }else{
        cout<<"Front is: "<<this->front->data<<endl;
        }
    }
    void printBack(){
        if(this->isEmpty()){
            cout<<"Empty queue!";
        }else{
        cout<<"Back is: "<<this->back->data<<endl;
        }
    }
    void printSize(){
        if(this->isEmpty()){
            cout<<"Empty queue!";
        }else{
        cout<<"Size is: "<<this->size<<endl;
        }
    }

    void push(int data){
        Node *newNode=new Node(data);
        if(this->size==0){
            this->front=newNode;
            this->back=newNode;

        }else{
           this->back->next=newNode;
            this->back=newNode;
        }
        this->size++;
    }
    void pop(){
        if(this->isEmpty()){
            cout<<"Empty queue nothing to pop!"<<endl;
        }else{
            Node *deleteNode=this->front;
            this->front=deleteNode->next;
            cout<<deleteNode->data<<" poped!"<<endl;
            delete deleteNode;
            this->size--;
            deleteNode=nullptr;
         

        }
    }

    void traverse(){
        if(this->isEmpty()){
            cout<<"Empty queue!"<<endl;
        }else{
            Node *ptr=this->front;
            int i=1;
            while(ptr!=nullptr){
                cout<<"Element ("<<i++<<") : "<<ptr->data<<endl;
                ptr=ptr->next;
            }
        }
    } 

};


struct DequeNode{
    int data;
    DequeNode* next;
    DequeNode* prev;

    DequeNode(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

class Dequeue{
    private:
    DequeNode* front;
    DequeNode* back;
    int size;

    public:
    Dequeue(){
        this->front=nullptr;
        this->back=nullptr;
        this->size=0;
    }
    int isEmpty(){
        if(this->size<=0){
            return 1;
        }else{
            return 0;
        }
        return -1;
    }
    void printFront(){
        if(this->isEmpty()){
            cout<<"Empty Dequeue!";
        }else{
        cout<<"Front is: "<<this->front->data<<endl;
        }
    }
    void printBack(){
        if(this->isEmpty()){
            cout<<"Empty Dequeue!";
        }else{
        cout<<"Back is: "<<this->back->data<<endl;
        }
    }
    void printSize(){
        if(this->isEmpty()){
            cout<<"Empty Dequeue!";
        }else{
        cout<<"Size is: "<<this->size<<endl;
        }
    }

    void push_front(int data){
        DequeNode* newNode=new DequeNode(data);
        if(this->size==0){
            this->front=newNode;
            this->back=newNode;
        }else{
            this->front->next=newNode;
            newNode->prev=this->front;
            this->front=newNode;
        }
        this->size++;
    }
    void push_back(int data){
        DequeNode* newNode=new DequeNode(data);
        if(this->size==0){
            this->front=newNode;
            this->back=newNode;
        }else{
            this->back->prev=newNode;
            newNode->next=this->back;
            this->back=newNode;
        }
        this->size++;
    }

    void pop_front(){
        if(this->isEmpty()){
            cout<<"Empty Dequeue nothing to pop!"<<endl;
        }else 
        {
            DequeNode*deleteNode=this->front;
            if(this->front==this->back)  {
                this->front=nullptr;
                this->back=nullptr;
            }else{
                this->front=this->front->prev;
                this->front->next=nullptr;
            }
            cout<<deleteNode->data<<" poped!"<<endl;
            delete deleteNode;
            deleteNode=nullptr;
            this->size--;
        }
    }
    void pop_back(){
        if(this->isEmpty()){
            cout<<"Empty Dequeue nothing to pop!"<<endl;
        }else 
        {
            DequeNode*deleteNode=this->back;
            if(this->front==this->back)  {
                this->front=nullptr;
                this->back=nullptr;
            }else{
                this->back=this->back->next;

                this->back->prev=nullptr;
            }
            cout<<deleteNode->data<<" poped!"<<endl;
            delete deleteNode;
            deleteNode=nullptr;
            this->size--;
        }
    }

    void traverse(){
        if(this->isEmpty()){
            cout<<"Empty Dequeue!"<<endl;
        }else{
            DequeNode *ptr=this->back;
            int i=1;
            while(ptr!=nullptr){
                cout<<"Element ("<<i++<<") : "<<ptr->data<<endl;
                ptr=ptr->next;
            }
        }
    } 
};


int main(){

    
    int size=0;
    bool exit =false;
    int action=0;
    int data=0;
    int updatedData=0;

   

    Dequeue l;
 
 
    while(!exit){
     cout<<endl<<"(1) for push front"<<endl<<"(2) for delete front"<<endl<<"(3) to  traverse forward"<<endl<<"(4) to push back"<<endl<<"(5) to exit"<<endl<<"(6) pop back"<<endl<<"(7) for size"<<endl;
     cout<<"Enter: ";
     cin>>action;
 
     switch(action){
         case 1:
         cout<<"Enter data to insert: ";
         cin>>data;
         l.push_front(data);
         break;
 
         case 2:
         l.pop_front();
         break;
 
         case 3:
         l.traverse();
         break;
 
         case 4:
         cout<<"Enter data to insert: ";
         cin>>data;
         l.push_back(data);
         break;
 
         case 5:
         exit=true;
         break;

         case 6:
         l.pop_back();
         break;
         case 7:
         l.printSize();
         break;
 
         default:
         cout<<"Invalid input";
     }
 
    }
 
    // while(!exit){
    //  cout<<endl<<"(1) for insertion"<<endl<<"(2) for deletion"<<endl<<"(3) to  traverse forward"<<endl<<"(4) to print top"<<endl<<"(5) to exit"<<endl<<"(6) for back"<<endl<<"(7) for size"<<endl;
    //  cout<<"Enter: ";
    //  cin>>action;
 
    //  switch(action){
    //      case 1:
    //      cout<<"Enter data to insert: ";
    //      cin>>data;
    //      l.push(data);
    //      break;
 
    //      case 2:
    //      l.pop();
    //      break;
 
    //      case 3:
    //      l.traverse();
    //      break;
 
    //      case 4:
    //      l.printFront();
    //      break;
 
    //      case 5:
    //      exit=true;
    //      break;

    //      case 6:
    //      l.printBack();
    //      break;
    //      case 7:
    //      l.printSize();
    //      break;
 
    //      default:
    //      cout<<"Invalid input";
    //  }
 
    // }
 

 
     
 
     return 0;
 }