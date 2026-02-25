/*
// QUEUE -> Using Linked List
#include<iostream>
using namespace std;
class Queue{
    struct Node{
        public:
        int data;
        Node* next;
        //Constructor
        Node(int val){
            data = val;
            next = nullptr;
        }
    };
    public:
    Node* front;
    Node* rear;
    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    //Front -> 5 -> 10 -> 15 -> Rear
    //Method --> Inside a class we call it a method
    //Enqueue --> Insert / Add element at rear 
    void enQueue(int val){
        Node* newNode = new Node(val);
        if(front == nullptr){
            front = rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode;
        }
        cout<<"\n"<<val<<" is inserted at rear in queue.\n";
    }
    //Dequeue --> Delete / Remove element from front
    void deQueue(){
        if(front==nullptr){
            cout<<"Queue is underflow(emmpty)\n";
            return;
        }
        Node* temp = front;
         cout<<"\n"<<front->data<<"is dequeue.\n";
        front = front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
    }
    //Peek --> See front element
    void peek(){
        if(front==nullptr){
            cout<<"Queue is empty\n";
            return;
        }
        cout<<"Front Element: "<<front->data<<endl;
    }
    //Display
    void display(){
        if(front == nullptr){
            cout<<"Queue is empty.\n";
            return;
        }
        Node* temp=front;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    q.enQueue(5);
    q.enQueue(10);
    q.enQueue(15);
    q.display();

    cout<<"Dequeue:\n";
    q.deQueue();
    q.display();
     
    cout<<"After Inqueue:\n";
    q.enQueue(20);
    q.display();

    q.peek();
}
*/
//Queue
//1.Queue using Array
//2.Enqueue
//3.Dequeue
//4.Peek
//5.isEmpty
//6.isFull
//7.Step-by-step visualization
//8.Internal pointer movement
#include<iostream>
using namespace std;
class Queue{
    private:
    int front;
    int rear;
    int size;
    int* arr;
    public:
    Queue(int s){
        size = s;
        front = -1 ;
        rear = -1 ;
        arr = new int[size];
    }
    //Check Queue is empty or not
    bool isEmpty(){
        return(front==-1||front>rear);
    }
    //Check Queue is full or not
    bool isFull(){
        return(rear==size-1);
    }
    //Enqueue
    void enQueue(int val){
        if(isFull()){
            cout<<"Stack is overflow.\n";
            return;
        }
        if(front==-1){
            front=0;
        }
        rear++;
        arr[rear]=val;
        cout<<val<<" inserted\n";
    }
    //Dequeue
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return;
        }
        cout<<arr[front]<<"removed\n";
        front++;
    }
    //Peek
    void peek(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        }
        cout<<"Front element:"<<arr[front]<<endl;
    }
    //Display
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty.\n";
            return;
        }
        cout<<"Queue:";
        for(int i= front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~Queue(){
        delete[] arr;
    }      
};
int main(){
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.peek();
    return 0;
}
