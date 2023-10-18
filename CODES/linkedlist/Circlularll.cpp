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
};

void traversal(Node* &head){
    if (head==nullptr)
    {
        cout<<"Empty list !"<<endl;
    }
    else
    {
        Node* ptr=head;
        int i=1;
        do
        {
        cout<<"Element: "<<i++<<" :"<<ptr->data;
        cout<<endl;
        ptr=ptr->next;
        } while (ptr!=head);
        
    }
    
}

void Insert(Node* &head, int data){
    Node* newnode = new Node(data);
    if(head==nullptr){
        head=newnode;
        newnode->next=newnode;
    }
    else{
        Node* ptr=head;
        do
        {
           ptr=ptr->next;
        } while (ptr->next!=head);
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
}
void deletelist(Node* &head,int data){
    if (head==nullptr)
    {
        cout<<"No Element to delete !"<<endl;
    }
    else
    {
        Node* ptr=head;
        do
        {
           ptr=ptr->next;
        }while (ptr->next->data!=data);
        //deleting when there is only one node is present;
        if(ptr==ptr->next){
            head=nullptr;
            delete ptr;
        }
        else //deleting when there are multiple nodes  present;
        {   
            // deleting first element
            if(ptr->next==head && head->data==data){
                Node* deletenode=ptr->next;
                head=deletenode->next;
                ptr->next=deletenode->next;
                delete deletenode;
            }else{
                // deleting middle element
                Node* deletenode=ptr->next;
                ptr->next=deletenode->next;
                delete deletenode;
            }
            
        }       
      

    }
}

int main(){
    Node* head=nullptr;
    Insert(head,10);
    Insert(head,20);
    Insert(head,30);
    Insert(head,40);
    traversal(head);
    deletelist(head,10);
    cout<<"after delete- "<<endl;
    traversal(head);
    return 0;
}