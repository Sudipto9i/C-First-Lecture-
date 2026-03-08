
// 4. MAP 
// Q11. Write a program to store student roll and name using name
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> s;
    s[101]="Rahim";
    s[102]="Karim";
    s[103]="Soham";
    for(auto x:s){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

//Q12: Count Frequency of Numbers using map
// Input: 1 2 2 3 1 4 2 
#include<iostream>
#include<map>
using namespace std;
int main(){
    int arr[]={1,2,2,3,1,4,2};
    map<int , int> m;
    for(int i=0;i<7;i++){
        m[arr[i]]++;
    }
    for(auto x:m){
        cout<<x.first<<"->"<<x.second<<endl;
    }
}

// Q13 : Write a program to count frequency of characters in a string using map.
// Example: 
// Input: banana
// Output: 
// b->1 
// a->3
// c->2
#include<iostream>
#include<map>
using namespace std;
int main(){
    string s = "banana";
    map<char,int> m;
    for(char c : s){
        m[c]++;
    }
    for(auto x:m){
        cout<<x.first<<"->"<<x.second<<endl;
    }
}
