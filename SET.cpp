
// 3 . SET -- > Important Questions
// Q8. Write a program to store numbers in a set and print unique values.
// Input: 5 3 8 5 2 3 
// Output: 2 3 5 8 
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(8);
    s.insert(5);
    s.insert(2);
    s.insert(3);
    for(int x:s){
        cout<<x<<" ";
    }
}

//Q9: Write a program to count number of unique elements using set.
// Input: 10 20 20 30 10 
// Output: 3 
#include<iostream>
#include<set>
using namespace std;
int main(){
    int count = 0;
    set<int> s ;
    s.insert(10);
    s.insert(20);
    s.insert(20);
    s.insert(30);
    s.insert(10);
    for(int x:s){
        cout<<x<<" ";
        count++;
    }
    cout<<"\nTotal Numbers: "<<count<<endl;
}

// Q10 : Write a program that checks if a number exists in a set
// Set: 2 4 6 8 
// Check : 6
// Output: Found
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    s.insert(2);
    s.insert(4);
    s.insert(6);
    s.insert(8);
    int found;
    cin>>found;
    if(s.count(found)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
}
