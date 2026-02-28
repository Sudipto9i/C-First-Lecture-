//SECTION A — Basic Level (Must Be Perfect)
//1 . Create a Singly Linked List
// -->Insert 5 nodes
// -->Print the list
// -->Count total nodes
//2️⃣ Insert at Beginning
//Input: 10 20 30
//Insert 5 at beginning.
//What will be final list?
//3️⃣ Insert at Position k
// Given : 
// 10 -> 20 -> 40 -> 50
// Insert 30 at position 3 
// Write final list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    //Insert 5 Nodes
    void insertFirst(int n){
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }
    void insertEnd(int n){
        Node* newNode= new Node(n);
        if(head==nullptr){
            head = newNode;
            return;
        }
        Node* curr = head ;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    // Insert at Position k
    void insertAtPosition(int n, int k){
        if(k<0){
            cout<<"Invalid Position.\n";
            return;
        }
        Node* newNode = new Node(n);
        if(k==1){
            newNode->next = head;
            head = newNode;
        }
        int counter = 1 ;
        Node* curr = head;
        while(curr!=nullptr&&counter<(k-1)){
            curr = curr->next;
            counter ++;
        }
        newNode->next = curr ->next;
        curr->next = newNode;
    }
    // 4. Delete First Node
    // Given : 10 -> 20 -> 30 -> 40 -> 50 -> X
    // Now : 20 -> 30 -> 40 -> 50 -> X
    void deleteHead(){
        Node* curr=head;
        head = head->next;
        delete curr;
        return;
    }
    // 5. Delete Last Node
    // Given : 20-> 30->40->50->X
    void deleteLastNode(){
        Node* curr = head;
        while(curr->next!=nullptr&&curr->next->next!=nullptr){
        curr=curr->next;
        }
       Node* temp=curr->next;
       curr->next = curr->next ->next;
       delete temp;
       return;
    }
    //SECTION B ---> Medium Level
    // 6 . Reverse a Linked List
    // Given: 10->20->30->40->50->X
    // Reverse: 50->40->30->20->10->X
    void reverseLl(){
        Node* prev = nullptr;//Node behind current node
        Node* curr = head;
        Node* next = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        head= prev;
    }
    // 7. Find Middle Element 
    void findMiddle(){
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Middle Point : "<<slow->data<<endl;
    }
    // 8.Detect if List is Empty
    void listIsEmpty(){
        if(head==nullptr){
            cout<<"List is empty."<<endl;
            return;
        }
        bool found = false;
        Node* temp=head;
        while(temp!=nullptr){
            temp=temp->next;
            if(head==nullptr){
                found = true ;
                break;
            }
        }
        if(found){
            cout<<"List is empty."<<endl;
        }else{
            cout<<"List is not empty."<<endl;
        }
    }
    // 9. Search an Element
    void search(int key){
        bool found = false;
        if(head->data==key){
            found = true;
            return;
        }
        Node* temp = head;
        while(temp!=nullptr){
            temp=temp->next;
            if(temp->data==key){
                found = true;
                break;
            }
        }
        if(found){
            cout<<temp->data<<" is found."<<endl;
        }else{
            cout<<temp->data<<" is not found."<<endl;
        }
    }
    // 10. Count Even Numbers in List
    void countEven(){
        int counter = 0 ;
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data%2 ==0){
                counter++;
            }
            temp=temp->next;
        }
        cout<<"Total even numbers : "<<counter<<endl;
    }
    //SECTION C ---> Hard/Midterm Level
    // 1 1 Delete Node at Position k
    // ---> What happens if:
    // ---> k=0?
    // ---> k is greater than length?
    // ---> list has only one node?
    void deleteNodePosition(int k){
        if(k<0){
            cout<<"Invalid Position.\n";
            return;
        }
        if(k==0){
            Node* temp=head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        int counter = 1;
        while(curr!=nullptr&&counter<(k-1)){
            curr = curr ->next;
            counter++;
        }
        Node* temp=curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
    // 1 2 Remove Duplicates
    // Given : 1 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5 
    // After removing duplicates?
    void removeDuplicates(){
        if (head==nullptr) return;
        Node* curr = head;
        while(curr->next!=nullptr){
            if(curr->data==curr->next->data){
                Node* temp=curr->next;
                curr->next=curr->next->next;
                delete temp;
            }else{
                curr = curr->next;
            }
        }
    }
    // 1 3 Merge Two Sorted Lists
    // List 1 : 1 ->3->5
    // List 2  : 2->4->6
    Node* getHead(){
        return head;
    }
    void setHead(Node* h){
        head = h;
    }
    static Node* merge(Node* a , Node* b){
        if(!a) return b;
        if(!b) return a;
        if(a->data<b->data){
            a->next = merge(a->next ,b);
            return a ;
        }else{
            b->next = merge(a,b->next);
        }
    }
    // 1 4 Check these Linked List is Palindrome
    //--->Step 1 ->Find Middle(Slow & Fast pointer)
    //--->Step 2 ->Reverse second half
    //--->Step 3 ->Compare both halves
    bool isPalindrome(){
        if(head==nullptr||head->next==nullptr){
            return true;
        }
        // Step -1 : Find Middle 
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Step -2 : Reverse Second Half
        Node* prev=nullptr;
        Node* curr= slow;
        Node* next = nullptr;
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // Step -> 3 : Compare
        Node* first = head;
        Node* second = prev;
        while(second!=nullptr){
            if(first->data!=second->data){
                return false;
            }
            first = first ->next;
            second = second ->next;
        }
        return true;
    }
    // 2 . DETECT LOOP IN LINKED LIST
   // Logic

//Slow moves 1 step
//Fast moves 2 steps
//If they ever meet → Loop exists
//If fast becomes NULL → No loop
bool detectLoop(){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false ;
}
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"X"<<endl;
    }
    void countNodes(){
        int count = 0;
        Node* temp = head;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        cout<<"Total Nodes: "<<count<<endl;
    }
};
int main(){
    LinkedList myList;
   // myList.insertFirst(5);
   // a.insertEnd(1);
   // a.insertEnd(3);
   // a.insertEnd(5);
    //b.insertEnd(2);
    //b.insertEnd(4);
    //b.insertEnd(6);
   // a.display();
   // b.display();
   // result.setHead(LinkedList::merge(a.getHead(),b.getHead()));
    
   // result.display();
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.insertEnd(2);
    myList.insertEnd(1);
    myList.display();
    if(myList.isPalindrome()){
        cout<<"Linked List is palindrome."<<endl;
    }else{
        cout<<"Linked List is not palindrome."<<endl;
    }
    if(myList.detectLoop()){
        cout<<"Detect Loop."<<endl;
    }else{
        cout<<"Not detect loop."<<endl;
    }
   // myList.insertAtPosition(30,3);
    //myList.insertAtPosition(10,1);
    //myList.insertAtPosition(20,2);
    //myList.insertAtPosition(40,3);
    //myList.insertAtPosition(50,4);
   // myList.display();
   // myList.countNodes();
    //myList.deleteHead();
    //myList.display();
   // myList.deleteLastNode();
   // myList.display();
   //myList.reverseLl();
   //myList.display();
   //myList.findMiddle();
  // myList.listIsEmpty();
   //myList.search(3);
  // myList.countEven(); 
  // myList.deleteNodePosition(3);
   //myList.display();
   //myList.removeDuplicates();
   //myList.display();
}
