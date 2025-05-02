#include<iostream>
//first implementation
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class LinkedList{
    private:
    Node *head;

    public:
    LinkedList(){
        this->head=nullptr;
    }

    void insertAtEnd(int data){
        Node *newNode=new Node(data);
        //empty list
        if(this->head==nullptr){
           //point head to newnode
           this->head=newNode;
        }//non empty list
        else{
            //initialize a pointer
            Node *ptr=this->head;

            //find last node
            while(ptr->next!=nullptr){
                ptr=ptr->next;
            }
            ptr->next=newNode;

        }
    }

    void insertAtFront(int data){
        Node* newNode= new Node(data);
        if(this->head==nullptr){
            this->head=newNode;
        }
        else{
            newNode->next=this->head;
            this->head=newNode;
        }
    } 

    void deleteNodeByValue(int data){
        Node*ptr=head;
        Node *deleteNode;

        if (this->head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if(this->head->data==data){
            deleteNode=head;
            head=head->next;
            delete deleteNode;
            cout << "Node with value " << data << " deleted." << endl;
             return;

        }

        while(ptr->next!=nullptr&&ptr->next->data!=data ){
            ptr=ptr->next;
        }
        if(ptr->next==nullptr){
            cout<<"Node not found!";
            return;
        }else{
            deleteNode=ptr->next;
            ptr->next=ptr->next->next;
            delete deleteNode;
            cout << "Node with value " << data << " deleted." << endl;
        }
    }

    void updateValue(int data,int updatedValue){
        
        if (this->head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if(head->data==data){
            head->data=updatedValue;
        }else{
        Node*ptr=head;

        while(ptr->next!=nullptr&&ptr->data!=data){
            ptr=ptr->next;
        }
        if(ptr->next==nullptr&&ptr->data!=data){
            cout<<"data not foound";
            return;
        }
        ptr->data=updatedValue;
        }
    }

    void printList(){
        Node *ptr=this->head;
        int i=1;
        while(ptr!=nullptr){
            cout<<" Node:("<<i++<<") "<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }


};

class DoubleNode{
    public:
    int data;
    DoubleNode* prev;
    DoubleNode* next;

    DoubleNode(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};


class DoublyLinkedList{
    private:
    DoubleNode* head;
    DoubleNode* tail;

    public:
    DoublyLinkedList(){
        this->head=nullptr;
        this->tail=nullptr;
    }

    void insertAtEnd(int data){
        DoubleNode *newNode=new DoubleNode(data);
        if(head==nullptr){
            head=newNode;
            tail=newNode;
        }else{
            DoubleNode* ptr=tail;
            ptr->next=newNode;
            newNode->prev=ptr;
            tail=newNode;
        }
    }

    void traverseListForward(){
        DoubleNode*ptr=head;
        int i=1;
        while(ptr!=nullptr){
            cout<<" Node:("<<i++<<") "<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }

    void traverseListBackWard(){
        DoubleNode*ptr=tail;
        int i=1;
        while(ptr!=nullptr){
            cout<<" Node:("<<i--<<") "<<ptr->data<<endl;
            ptr=ptr->prev;
        }
    }

    void deleteNodeByValue(int data){
        DoubleNode * deleteNode;
        

        if(head->data==data){
            cout << "Node with value " << data << " deleted." << endl;
            deleteNode=head;
            if(head==tail){
                head=nullptr;
                tail=nullptr;
                
            }else{
            head=head->next;
            head->prev = nullptr;
            }
            delete deleteNode;
        }else if(tail->data==data){
            cout << "Node with value " << data << " deleted." << endl;
            deleteNode=tail;
            tail=tail->prev;
            tail->next = nullptr;
            delete deleteNode;

        }        
        else{
            DoubleNode*ptr=this->head;
            while(ptr!=nullptr&&ptr->next->data!=data){
                ptr=ptr->next;
            }
            if(ptr==nullptr||ptr->next==nullptr){
                cout<<"Data not found";
                return;
            }
            cout << "Node with value " << data << " deleted." << endl;
            deleteNode=ptr->next;
            ptr->next=deleteNode->next;
            deleteNode->next->prev=ptr;
            deleteNode=nullptr;
            delete deleteNode;

        }

    }

};


class CircularSinglyList{

    private:
    Node *head;

    public:
    CircularSinglyList(){
        this->head=nullptr;
    }

    void insert(int data){
        Node* newNode= new Node(data);
        if(this->head==nullptr){
            //empty list 
            this->head=newNode;
            newNode->next=newNode;
        }else{
            Node*ptr=head;
            while(ptr->next!=this->head){
                ptr=ptr->next;
            }
            ptr->next=newNode;
            newNode->next=head;
        }
    }

    void traverseList(){
        if(this->head==nullptr){
            cout<<"Empty List!"<<endl;
        }else{
            int i=1;
            Node* ptr=head;
            do{
                cout<<" Node:("<<i++<<") "<<ptr->data<<endl;
                ptr=ptr->next;
            }while(ptr!=head);
        }
    }

    void deleteNode(int data){
        if(this->head==nullptr){
            cout<<"Empty List!"<<endl;
        }else if(this->head->data==data){
            Node* deleteNode=head;
            this->head=deleteNode->next;
            //find last
            Node * ptr=head;
            while(ptr->next!=deleteNode){
                ptr=ptr->next;
            }
            ptr->next=this->head;
            cout<<"Data "<<data<<"deleted!";
            delete deleteNode;
            deleteNode=nullptr;
        }else{
            Node *ptr=head;
            // for this we also need  to prevent endless loop if data in not present
            do{
                if(ptr->next->data==data){
                    break;
                }
                ptr=ptr->next;
            }while(ptr->next!=head);

            if(ptr->next->data!=data&&ptr==head){
                cout<<"Data "<<data<<"to be deleted Not found";
            }else{
                Node *deleteNode=ptr->next;
                ptr->next=deleteNode->next;
                cout<<"Data "<<data<<"deleted!";
                delete deleteNode;
                deleteNode=nullptr;
            }
        }
    }

   

};

int main(){
//    LinkedList l;
//    DoublyLinkedList l;

   CircularSinglyList l;
   bool exit =false;
   int action=0;
   int data=0;
   int updatedData=0;


   while(!exit){
    cout<<endl<<"(1) for insertion"<<endl<<"(2) for deletion"<<endl<<"(3) to  traverse forward"<<endl<<"(4) to traverse backward"<<endl<<"(5) to exit"<<endl;
    cout<<"Enter: ";
    cin>>action;

    switch(action){
        case 1:
        cout<<"Enter data to insert: ";
        cin>>data;
        l.insert(data);
        break;

        case 2:
        cout<<"Enter data to delete: ";
        cin>>data;
        l.deleteNode(data);
        break;

        case 3:
        l.traverseList();
        break;

        case 4:
        // cout<<"Enter old data: ";
        // cin>>data;
        // cout<<endl<<"Enter new data: ";
        // cin>>updatedData;
        // l.updateValue(data,updatedData);
        // l.traverseListBackWard();
        break;

        case 5:
        exit=true;
        break;

        default:
        cout<<"Invalid input";
    }

   }


//    while(!exit){
//     cout<<endl<<"(1) for insertion"<<endl<<"(2) for deletion"<<endl<<"(3) to  view list"<<endl<<"(4) to update"<<endl<<"(5) to exit"<<endl;
//     cout<<"Enter: ";
//     cin>>action;

//     switch(action){
//         case 1:
//         cout<<"Enter data to insert: ";
//         cin>>data;
//         l.insertAtEnd(data);
//         break;

//         case 2:
//         cout<<"Enter data to delete: ";
//         cin>>data;
//         l.deleteNodeByValue(data);
//         break;

//         case 3:
//         l.printList();
//         break;

//         case 4:
//         cout<<"Enter old data: ";
//         cin>>data;
//         cout<<endl<<"Enter new data: ";
//         cin>>updatedData;
//         l.updateValue(data,updatedData);
//         break;

//         case 5:
//         exit=true;
//         break;

//         default:
//         cout<<"Invalid input";
//     }

//    }


    

    return 0;
}