
//2.Queue --> Important Questions
//Q5.Write a program using STL queue to insert 5 integers and print them.
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

//Q6 . Write a program to simulate people standing in a queue.
// Input : 
// Person1 
// Person2 
// Person3 
// Print them in FIFO order.
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<string> q;
    q.push("Person1");
    q.push("Person2");
    q.push("Person3");
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}
//Q7
// Write a program that removes even numbers from a queue.
// Input: 1 2 3 4 5 
// Output: 1 3 5 
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.empty()){
        if(q.front()%2!=0){ 
            cout<<q.front()<<" ";
        }
        q.pop();
    }
    return 0;
}





