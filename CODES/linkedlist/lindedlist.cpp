#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(int value){
        this->data=value;
        next=nullptr;
    }
    Node(){
        next=nullptr;
    }
};
void linkedListTaraversal(Node* head) {
    if (head == nullptr) {
        cout << "Empty Linkedlist!" << endl;
        return;
    }
    Node* ptr = head;
    int i=1;
    while (ptr != nullptr) {
        // cout <<"Element "<<i++<<" :"<<ptr->data << endl;
        cout <<ptr->data << " , ";
        ptr = ptr->next;
    }
}

void insertAtFront(Node* &head,Node* & tail,int data){
    if(head==nullptr){
        Node* newnode= new Node(data);
        head=newnode;
        tail=newnode;
    }
    else{   
        Node* newnode= new Node(data);
        newnode->next=head;
        head=newnode;      
    }    
}

void insertAtBack( Node* &head,Node* &tail, int data){
        if(tail==nullptr){
            Node* newnode = new Node(data);
            tail=newnode;
            head=newnode;
        }
        else{
            Node* newnode =new Node(data);
            tail->next=newnode;
            tail=newnode;
        }
}


void inserAtPosition(Node*head,Node* tail, int data,int pos){
    
    if(pos==1){
        insertAtFront(head,tail,data);
    }
    else{
        Node* newnode= new Node(data); 
        Node* ptr=head;
        int i=1;
        while (i<pos-1)
        {
           ptr=ptr->next;
           i++;
        }
        if(ptr==tail){
            ptr->next=newnode;
            tail=newnode;
        }
        else{
             newnode->next=ptr->next;
            ptr->next=newnode;
        }
              
    }
}

void deleteLinkenList(Node* &head,int pos){
    if(head==nullptr){
        cout<<"Empty Linked list!";
    }
    else
    if(pos==1){
        Node* temp=head;
        head=temp->next;
        delete temp;
    }
    else{
        Node* ptr=head;
        int i=1;
        while(i<pos-1){
            ptr=ptr->next;
            i++;
        }
        Node* temp=ptr->next;
        ptr->next=temp->next;
        delete temp;
    }
}
 Node* reverseList(Node* head) {
        if(head==NULL){
            return 0;
        }
        if(head->next==NULL ){
            return head;
        }else
        {     
            //for two node
            Node* ptr1=head->next;
            Node* ptr2=head->next->next;
            if(ptr2==NULL){
                ptr1->next=head;
                head->next=NULL;
                return ptr1;
            }
            else
            {
                bool first =true;
                while(ptr2->next!=NULL){
                    if(first){
                        head->next=NULL;
                        ptr1->next=head;
                        head=ptr1;
                        ptr1=ptr2;
                        ptr2=ptr2->next;
                        first=false;
                    }else
                    {
                        ptr1->next=head;
                        head=ptr1;
                        ptr1=ptr2;
                        ptr2=ptr2->next;
                    }

                }
                //for three nodes
                if(first){
                     head->next=NULL;
                        ptr1->next=head;
                        head=ptr1;
                        ptr2->next=ptr1;
                        ptr1=ptr2;
                        first=false;
                        return ptr2;
                }
                else{
                        ptr1->next=head;
                        head=ptr1;
                        ptr2->next=ptr1;
                        ptr1=ptr2;
                        return ptr2;
                }
            }
        }
    }

     Node* middleNode(Node* head) {
        Node* fast=head->next;
        Node* slow=head;
        int count=1;
        while(fast!=NULL){
            if(fast->next!=NULL){
                break;
            }
            fast=fast->next->next;
            slow=slow->next;
            count++;
        }
        if(count%2==0){
            slow=slow->next;
            return slow;
        }
        return slow;
    }
   void listswap(Node* first,Node* last,int i,int j){
        Node* ptr=first;
        if(i<j){
            cout<<first->data<<"-"<<last->data<<endl;
            swap(first->data,last->data);
            
            i++;
            j--;
            while(ptr->next!=last){
                ptr=ptr->next;
            }
            listswap(first->next,ptr,i,j);
        }
        
    }
    void reverselist(Node* first,Node* last,int k){
        // cout<<first->data<<"-"<<last->data<<endl;
         if(last!=NULL && last->next!=NULL){
                
            
        int i=1;
        int j=k;
        int cnt=1;
        while(cnt<k){
            if(last!=NULL && last->next!=NULL){
                
                last=last->next;
                cnt++;
            }
            
        }
        listswap(first,last,i,j);
        cout<<first->data<<"-"<<last->data<<endl;
        reverselist(last->next,last->next,k);
        }
    }

int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int data=20;
  
    insertAtBack(head,tail,data);
    insertAtBack(head,tail,30);
    insertAtBack(head,tail,40);
    insertAtBack(head,tail,50);
    insertAtBack(head,tail,60);
    insertAtBack(head,tail,70);
    // insertAtFront(head,tail,20);
    // insertAtFront(head,tail,60);
    linkedListTaraversal(head);
    cout<<endl;
    reverselist(head,head,2);
//    deleteLinkenList(head,1);
//    inserAtPosition(head,tail,10,4);
    // head=middleNode(head);
    // cout<<"head="<<head->data<<endl;
   linkedListTaraversal(head);


 // insertAtFront(head,70);
    // insertAtFront(head,80);
       // Node* first= new Node(10);
    // Node* second= new Node(20);
    // head->next=first;
    // first->next=second;
    // delete first;
    // delete second;
    // delete head;
   
    // cout<<newnode->data<<endl;
    // cout<<newnode->next<<endl;
    //same thing
    
    // cout<<first<<endl;
    // cout<<head->next<<endl;

    return 0;
}