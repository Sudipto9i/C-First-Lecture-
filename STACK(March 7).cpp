
// Q1 
// Write a C++ program using STL stack to push 5 numbers and print them by popping.
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    // top -- > show top 
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

//Q2 . Write a program to reverse a string using stack.
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str = "HELLO";
    stack<char> s;
    for(char c: str){
        s.push(c);
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

//Q3
// Write a program to check whether parentheses are balanced.
// Example 1:
// Input: (a+b)*(c+d)
// Output: Balanced 
// Example 2:
// Inout : (a+b* (c-d)
// Output : Not Balanced 
#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str = "(a+b)*(c+d)";
    stack<char>s;
    for(char c : str){
        if(c=='('){
            s.push(c);
        }
        if(c==')'){
            if(!s.empty()){
                s.pop();
            }
        }
    }
    if(s.empty()){
        cout<<"Balanced.";
    }else{
        cout<<"Not Balanced.";
    }
}

// Q4 : write a program to evaluate postfix expression using stack.
// Example : 
// Input : 23*54*+9-
// Output : 17
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string expression;
    cout<<"Enter postfix expression:";
    cin>>expression;
    stack<int> s;
    for(char c : expression){
        if(isdigit(c)){
            //convert char to int and push
            s.push(c-'0');//Convert char to int 
        }else{
            // Operator encountered
            // It's an operator - pop and evaluate
            int operand2 = s.top();s.pop();
            int operand1 = s.top();s.pop();
            switch(c){
                case '+':
                s.push(operand1 + operand2);
                break;
                case '-':
                s.push(operand1 - operand2);
                break;
                case '*':
                s.push(operand1 * operand2);
                break;
                case '/':
                s.push(operand1 / operand2);
                break;
            }
        }
    }
    cout<<"Result : "<<s.top()<<endl;
    return 0;
}
