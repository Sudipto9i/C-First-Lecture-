
//STl-->Standard Template Library
//It is a collection of ready-made data structures and algorithoms in C++.

//VECTOR(MOST IMPORTANT)
//Dynamic array(size changes automatically)
//Contiguous memory(like array)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);//add
    v.push_back(20);
    v.push_back(30);
    cout<<"Size: "<<v.size()<<endl;
    //Method 1:Index-based traversal
    for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
    }
    cout<<endl;
    //Method 2:Range-based for loop
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    //Ascending sort--> Low to High
    sort(v.begin(),v.end());
    cout<<"Ascending: ";
    for(auto x : v ) cout<<x<<" ";
    cout<<endl;
    //Descending sort-->High to Low
    sort(v.rbegin(),v.rend());
    cout<<"Descendong: ";
    for(auto x:v)cout<<x<<" ";
    cout<<endl;
    //Other operations
    v.pop_back();//Remove last element
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<"After pop_back , size: "<<v.size()<<endl;
    cout<<"Is empty?"<<(v.empty()?"Yes":"No")<<endl;
    v.clear();//Remove all elements
    cout<<"After clear , size: "<<v.size()<<endl;
}

//STACK
//LIFO-->LAST IN FIRST OUT
//Container Adapter-wraps underlying container(default:deque)
//No iteration allowed(no begin()/end())
#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<string>
using namespace std;
//2.Common Stack Applications
//A.Parentheses Matching
bool isValidParentheses(string str){
    stack<char>s;
    for(char c:str){
        if(c=='('||c=='{'||c=='['){
            s.push(c);//push opening brackets
        }else if(c==')'||c=='}'||c==']'){
            if(s.empty())return false;
            char top = s.top();
            if((c==')'&& top=='(')||
               (c=='}'&&top=='{')||
               (c==']'&&top==']')){
                s.pop();//Match found
               }else return false;//Mismatched brackets
        }
        //Other characters (a,b,+,-,etc.) are IGNORED
    }
    return s.empty();// All brackets matched?
}
int main(){
    //Declearition ways
    stack<int> s1;//default(deque)
    stack<int,vector<int>>s2;//using vector
    stack<int,list<int>>s3;//using list
    stack<int,deque<int>>s4;//explicit deque
    //BASIC OPERATIONs
    stack<int> st;
    //1. push()-->add element to top
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    //2.top()-->access top element(doesn't remove)
    cout<<"Top element: "<<st.top()<<endl;
    //3.pop() --> remove top element(no return value!)
    st.pop();//remove 40
    cout<<"After pop, top: "<<st.top()<<endl;
    //4.size()-->number of elements
    cout<<"Size: "<<st.size()<<endl;
    //5.empty()-->check if stack is empty
    if(st.empty()){
        cout<<"Stack is empty"<<endl;
    }else{
        cout<<"Stack has "<<st.size()<<" elements"<<endl;
    }
    stack<int> st1,st2;
    st1.push(1);
    st1.push(2);
    st2.push(100);
    st1.swap(st2);
    cout<<"ST1 size: "<<st1.size()<<endl;
    cout<<"ST2 size: "<<st2.size()<<endl;
    //1.Traversing Stack(Without Destroying)
    //Method 1 : Copy and pop
    stack<int> temp = st;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
    //Original stack s remains intact

    //Method 2 : Store in vector(reverse order)
    vector<int> elements;
    while(!st.empty()){
        elements.push_back(st.top());
        st.pop();
    }
    //Now traverse elements
    for(auto x:elements)cout<<x<<" ";
    cout<<"\n--- Testing Parentheses Validation ---"<<endl;
    //Test 1: Valid expression
    string expr1 = "(a+b)-c";
    if(isValidParentheses(expr1)){
        cout<<expr1<<" is VALID"<<endl;
    }else{
        cout<<expr1<<" is INVALID"<<endl;
    }
    //Test 2: Invalid Expression
    string expr2 = "((a+b)-c";
    if(isValidParentheses(expr2)){
        cout<<expr2<<" is VALID"<<endl;
    }else{
        cout<<expr2<<" is INVALID"<<endl;
    }
    //Test 3: Complex valid expression
    string expr3 = "{[a+(b-c)]*d}";
    if(isValidParentheses(expr3)){
        cout<<expr3<<" is VALID"<<endl;
    }else{
        cout<<expr3<<" is INVALID"<<endl;
    }
    //Test 4:Multiple test Cases
    cout<<"\n--- Multiple Test Cases---"<<endl;
    string tests[]={"()","([])","({[})","((()))","(a+b","a+B"};
    for(string test : tests){
        cout<<test<<" -> "<<(isValidParentheses(test)?"VALID":"INVALID")<<endl;
    }
    return 0;
}

//QUEUE - FIFO (First In First Out)
//Container Adapter -- wraps underlying container (default:deque)
//No iteration allowed(no begin()/end())
//VERY IMPORTANT for BFS algorithms!
#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<string>
using namespace std;
int main(){
    // ============ DECLARATION WAYS ===========
    queue<int> q1;//default(dequeue)
    queue<int, vector<int>>q2;//using vector
    queue<int, list<int>>q3;//using list
    queue<int, deque<int>>q4;//explicit deque
    //===============BASIC OPERATIONS===========
    queue<int> q ;
    // 1 . push()-add element to back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    //2.front()-access first element(doesn't remove)
    cout<<"Front Element: "<<q.front()<<endl;
    //3.back()-access last element(doesn't remove)
    cout<<"Back Element: "<<q.back()<<endl;
    //4.pop()-remove front element (no return value)
    q.pop();
    cout<<"After Pop, front: "<<q.front()<<endl;
    //5.size()--Number of elements
    cout<<"Size:"<<q.size()<<endl;
    //6.empty()--Check if queue is empty
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue has: "<<q.size()<<" elements."<<endl;
    }
    //7.swap()--swap contents of two queues
    queue<int> qa , qb;
    qa.push(1);
    qa.push(2);
    qb.push(100);
    qa.swap(qb);
    cout<<"After swap - qa size: "<<qa.size()<<endl;
    cout<<"After swap - qb size: "<<qb.size()<<endl;
    //8.emplace() -- Construct in-place
    queue<pair<int,string>>qp;
    qp.emplace(10,"hello");//Direct construction
    //This creates temporary
    return 0;
}

//SET
//Unique elements -no duplicates allowed
//Automatically sorted(ascending by default)
//Implemented as Red-Black Tree(balanced BST)
//O(log n)for insert , delete , search
//Associative container (elements referenced by value, not position)
#include<iostream>
#include<set>
#include<unordered_set>
#include<string>
using namespace std;
int main(){
    //=========DECLARATION WAY=========
    set<int>s1;// ascending order
    set<int,greater<int>>s2;//descending order
    set<int,less<int>>s3;//string set
    set<string>s4;//string set(lexicographical or der)
    //=========BASIC OPERATIONS ==========
    set<int> s;
    // 1 . insert()--->add element(duplicate ignored)
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(8);
    s.insert(2);
    //2.Iterate(automatically sorted!)
    cout<<"Set elements(sorted):";
    for(int x:s){
        cout<<x<<" ";//Output : 1 2 3 5 8
    }
    cout<<endl;
    // 3. size() --> number of elements
    cout<<"Size: "<<s.size()<<endl;//5(not 6)
    // 4 . empty() --> check if empty
    if(s.empty()){
        cout<<"Set is empty."<<endl;
    }else{
        cout<<"Set has "<<s.size()<<" elements"<<endl;
    }
    //5 . find() -->search element(return iterator)
    auto it = s.find(3);
    if(it!=s.end()){
        cout<<"Found: "<<*it<<endl;
    }else{
        cout<<"Not found"<<endl;
    }
    //6. count()-check existance(return 0 or 1 for set)
    if(s.count(5)){
        cout<<"% exists in set"<<endl;
    }
    //7.erase() -- > remove elements
    s.erase(3);//erase by value
    s.erase(s.begin());//erase by iterator(remove 1)
    s.erase(s.find(5),s.end());//erase range
    //8.clear()-->remove all elements
    s.clear();
    //9.insert with pair return value(important!)
    auto result=s.insert(10);
    if(result.second){
        cout<<"Inserted successfully"<<endl;
    }else{
        cout<<"Element already exists"<<endl;
    }
    return 0;
}
*/
//MAP
//Key-Value pairs (dictionary/associative array)
//Keys are unique and sorted (ascending by default)
//Implemented as Red-Black Tree (balanced BST)
//O(log n) for insert, delete, search
//Each key maps to exactly one value
#include<iostream>
#include<map>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    // ============ DECLARATION WAYS ===========
    map<string, int> m1;                              // ascending by key
    map<int, string, greater<int>> m2;                // descending by key
    map<string, int, less<string>> m3;                // ascending (explicit)

    // ============ BASIC OPERATIONS ===========
    map<string, int> m;

    // 1. Insert using [] operator
    m["apple"] = 5;
    m["banana"] = 3;
    m["cherry"] = 8;

    // 2. Insert using insert()
    m.insert({"date", 4});
    m.insert(pair<string, int>("elderberry", 6));
    m.insert(make_pair("fig", 7));

    // 3. Access using [] (creates if not exists!)
    cout << "Apple: " << m["apple"] << endl;     // 5
    cout << "Grape: " << m["grape"] << endl;     // 0 (creates grape!)

    // 4. Access using at() (throws exception if not exists)
    cout << "Banana: " << m.at("banana") << endl;  // 3
    // cout << m.at("kiwi");  // Throws out_of_range exception

    // 5. Iterate (automatically sorted by key!)
    cout << "\nMap contents (sorted by key):" << endl;
    for(auto x : m) {
        cout << x.first << " -> " << x.second << endl;
    }

    // 6. find() - search by key
    auto it = m.find("cherry");
    if(it != m.end()) {
        cout << "\nFound: " << it->first << " = " << it->second << endl;
    }

    // 7. count() - check if key exists (0 or 1 for map)
    if(m.count("date")) {
        cout << "Date exists!" << endl;
    }

    // 8. erase() - remove by key or iterator
    m.erase("fig");                    // erase by key
    m.erase(m.find("grape"));          // erase by iterator
    m.erase(m.begin(), m.find("date")); // erase range

    // 9. size() and empty()
    cout << "Size: " << m.size() << endl;
    if(m.empty()) cout << "Map is empty" << endl;

    // 10. clear() - remove all
    // m.clear();

    return 0;
}
































