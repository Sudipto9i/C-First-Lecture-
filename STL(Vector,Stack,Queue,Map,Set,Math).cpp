
// STL = Standard Template Library
// It is a collection of ready-made data structures and algorithms in C++.
// Instead of writing everything from scratch (like linked List , stack etc). STL already gives them.
// 1. Containers --> store data 
// Example : vector , stack , queue , map , set
// 2. Algorithms --> operations on data
// Example : sort() , reverse(), find()
// 3. Iterators --> used to traverse containers 
// VECTOR (Most Immportant)
// What is Vector?
// A dynamic array.
// Array size is fixed.
// Vector size can grow automatically.
// Array --> int arr[5]
// Vector --> vector<int> v
// Important Vector Functions 
// Function               // Meaning 
// push_back(x)              insert element 
// pop_back()                remove last 
// size()                    number of elements 
// clear()                   delete all
// empty()                   check empty
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

// 3.MATH(cmath library)
// Header: 
// #include<cmath>
// Important math functions:
// Function                 Meaning
// sqrt(x)                  square root
// pow(a,b)                 a^b
// ceil(x)                  round up
// floor(x)                 round down
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<sqrt(16)<<endl;
    cout<<pow(2,3)<<endl;
    cout<<ceil(3.1416)<<endl;//CEIL -> Round Up :: OUTPUT:4
    cout<<floor(3.1416)<<endl;//FLOOR->Round DOWN ::OUTPUT:3
}

// 4. STACK (STL)
// LIFO-->Last In , First Out
// Operations
// Function         Meaning
// push(x)          insert
// pop()            remove
// top()            show top
// empty()          check empty
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}

// 5 . QUEUE
// FIFO == First In First Out
// Header: include<queue>
// Create Queue: queue<int> q;
// Operations
// Function              Meaning
// push                  enqueue(Insert element at rear)
// pop                   dequeue(Remove element from front)
// front()               first element 
// back()                last element 
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q ;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}

// 6. MAP 
// Map stores key-value pairs 
// Example: 
// Roll -> Name 
// 101 -> Rahim
// 102 -> Karim
// Header: #include<map>
// Create Map : map<int , string> m;
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string>m;
    m[101]="Rahim";
    m[102]="Karim";
    //print
    for(auto x : m){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

//  7.SET
//  Set stores unique elements
//  No duplicates allowed.
//  Header: #include<set>
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s;
    s.insert(2);
    s.insert(4);
    s.insert(6);
    s.insert(2);
    for(int x:s){
        cout<<x<<" ";
    }
}
