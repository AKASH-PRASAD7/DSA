#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int n){
        this->data=n;
        this->next=nullptr;
    }
};

class stack{
    public:
    int size;
    int n=0;
    Node*top=nullptr;
    Node*head=nullptr;

    //stack creation
    stack(int n){
        if(n<=0){
            cout<<"Enter valid size!";
        }
        else{
                this->size=n;
            }
            
        }
    

        void stack_Push(int data)
        {
           //stack over flow
           if(this->n==this->size){
               cout<<"Stack Overflow !"<<endl;
           }else{
               //for first element
                if(this->n==0){
                   this->head=this->top;
                   this->head=new Node(data);
                   this->top=this->head;
                   this->n++;
               }else
               {
                Node* newnode=new Node(data);
                this->top->next=newnode;
                this->top=newnode;
                this->n++;
               }
           }
        }

  

        void stack_Pop(){
            if(this->n==0){
                cout<<"Stack underflow!"<<endl;
            }
            else{
                //poping first element
                if(this->n==1){
                    cout<<"Popped Element: "<<this->top->data<<endl;
                    delete(this->top);
                    this->top=nullptr;
                    this->head=nullptr;
                    this->n--;
                }
                else{
                    Node*ptr=this->head;
                    while(ptr->next!=this->top){
                        ptr=ptr->next;
                    }
                    cout<<"Popped Element: "<<this->top->data<<endl;
                    delete(this->top);
                    this->top=ptr;
                    this->n--;
                }
            }
        }

        void stack_Top(){
            if(this->top==nullptr){
                cout<<"Stack underflow!"<<endl;
            }
            else{
               cout<<"Top element: "<<this->top->data<<endl;
            }
        }

        void isEmpty(){
             if(this->top==nullptr){
                cout<<"Stack is empty"<<endl;
            }
            else{
               cout<<"Stack is NOT empty"<<endl;
            }
        }

        void print_Stack(){
            if(this->top==nullptr){
                cout<<"Stack underflow!"<<endl;
            }
            else{
                Node*ptr=this->head;
                cout<<"Elements: ";
                while(ptr!=this->top){
                    cout<<ptr->data<<",";
                    ptr=ptr->next;
                }
                   
            }
        }

};

int main(){

    int n=-1;
    int size=0;
    int data;
    
    cout<<"Enter size of stack: ";
    cin>>size;
    cout<<endl;
    stack s(size);
     while (size>0){
        cout<<endl;
        cout<<"Enter 0 to quit: "<<endl;
        cout<<"Enter 1 for pushing: "<<endl;
        cout<<"Enter 2 for poping"<<endl;
        cout<<"Enter 3 for ckecking isEmpty: "<<endl;
        cout<<"Enter 4 for top element: "<<endl;
        cout<<"Enter 5 to print all elements: "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"Enter :";
        cin>>n;
        cout<<endl;
        if(n==0){
            break;
        }
   
       switch (n)
       {
       case 1:
           cout<<"Enter element to be pushed: ";
           cin>>data;
           s.stack_Push(data);
           break;

        case 2:           
            s.stack_Pop();
            break;
        
        case 3:
            s.isEmpty();
            break;

         case 4:
            s.stack_Top();
            break;

        
         case 5:
            s.print_Stack();
            break;
        

       
       default:
            cout<<"Enter valid input!";
           break;
       }
   
 }
   

    return 0;
}