#include<iostream>
using namespace std;

class Queue{
    int size;
    int *arr;
    int peek;
    public:
    Queue(int s){
        size=s;
        arr=new int[size];
        peek=-1;
    }

    void Enqueue(int data){
        if(peek==size){
            cout<<"Queue is Full !"<<endl;
        }else{
           cout<<"Enqued: "<<data<<endl;
           arr[++peek]=data;
        }
    }

    void Dequeue(){
       if(peek==-1){
            cout<<"Queue is Empty !"<<endl;
        }else{
            cout<<"Dequed: "<<arr[peek--]<<endl;
        }
    }

    void front(){
         if(peek==-1){
            cout<<"Queue is Empty !"<<endl;
        }else{
            cout<<"Front: "<<arr[peek]<<endl;
        }
    }
};




int main(){
    int size;
    int data;
    cout<<"Enter Queue size: ";
    cin>>size;
    if(size<=0){
        cout<<"Enter valid size";
    }
    Queue q(size);
    int n=1;
    while(n!=0){
        cout<<"Enter 0 to  Exit   "<<endl;
        cout<<"Enter 1 to  Enqueue"<<endl;
        cout<<"Enter 2 to  Dequeue"<<endl;
        cout<<"Enter 3 for front  "<<endl;
        cout<<"-------------------"<<endl;
        cout<<"ENTER: ";
        cin>>n;
        cout<<endl;
        switch(n){
            case 0:           
            break;

            case 1:
            cout<<"Enter value to enqueue: ";
            cin>>data;
            cout<<endl;
            q.Enqueue(data);            
            break;

            case 2:
            q.Dequeue();            
            break;

            case 3:
            q.front();           
            break;

            default:
            cout<<"Enter valid Input !";
            break;
           
        }
    }

    return 0;
}