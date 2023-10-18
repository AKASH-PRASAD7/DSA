#include<iostream>
using namespace std;

class stack{
    public:
    int top=-1;
    int *arr;
    int size;
    stack(int size){
        if(size<=0){
            cout<<"Enter valid size !";
        }
        else{
            this->size=size;
            this-> arr= new int[size];
            top=-1;
        }
        
    }

    void stack_Push(int data){
        if(this->top==this->size-1){
            cout<<"Stack overflow! "<<endl;
        }else{
            this->top++;
            this->arr[this->top]=data;
            cout<<"Pushed "<<data<<"into stack"<<endl;
        }
    }
    void stack_Pop(){
        if(this->top==-1){
            cout<<"Stack underflows! "<<endl;
        }else{
            this->top--;
        }
    }
    void isEmpty(){
        if(this->top==-1){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"Stack is NOT empty"<<endl;
        }
    }
    void stack_Top(){
         if(this->top==-1){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"Top element "<<this->arr[this->top]<<endl;
        }
    }

    void print_Stack(){
        cout<<"Elements: ";
        for(int i=0; i<=this->top;i++){
            cout<<this->arr[i]<<",";
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
    
  
