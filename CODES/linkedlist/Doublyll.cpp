#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }

};

void traversal(Node* &head,Node* &tail){
    if(head==nullptr){
        cout<<"EMPTY LIST!"<<endl;
    }
    else{
        Node*ptr=head;
        int i=1;
        while(ptr!=nullptr){
        cout<<"Element: "<<i++<<" :"<<ptr->data;
        cout<<endl;
        ptr=ptr->next;
    }
    // cout<<"REVERSE-"<<endl;
    //     --i;
    //     ptr=tail;
    //     while(ptr!=nullptr){
    //          cout<<"Element: "<<i--<<" :"<<ptr->data;
    //          cout<<endl;
    //         ptr=ptr->prev;
    //     }
    }
}

void insertAttaiTail(Node* &head, Node* &tail,int data){
    Node* newnode =new Node(data);
    if(head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}

void insertAtHead(Node* &head, Node * &tail,int data){
    Node* newnode =new Node(data);
    if(head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void deleteValue(Node* &head, Node* &tail,int value){
    if(head==nullptr){
        cout<<"Can't Delete Empty List !"<<endl;
    }
      else{
        Node* ptr=head;
        while(ptr->data!=value){
            ptr=ptr->next;
        }
        //Deleting single element
            if(ptr->next==nullptr && ptr==head){
                head=nullptr;
                tail=nullptr;
                delete ptr;
            }else{
                //Deleting head
                if(ptr==head){      
                head=ptr->next;
                head->prev=nullptr;
                delete ptr;
                }
                //Deleting tail
                else{
                    if(ptr==tail){
                        tail=tail->prev;
                        tail->next=nullptr;
                        delete ptr;
                    }
                    //Deleting element between
                    else{
                        Node* prevnode=ptr->prev;
                        Node* nextnode=ptr->next;
                        prevnode->next=nextnode;
                        nextnode->prev=prevnode;
                        delete ptr;
                    }
                }
            }
       

        }

}

int main(){
    Node* head =nullptr;
    Node* tail =nullptr;

    // insertAttaiTail(head,tail,10);
    // insertAttaiTail(head,tail,20);
    // insertAttaiTail(head,tail,30);
    // insertAttaiTail(head,tail,40);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,80);
    insertAtHead(head,tail,100);
    traversal(head,tail);
    deleteValue(head,tail,80);
    cout<<"after delete"<<endl;
    traversal(head,tail);



    return 0;

}