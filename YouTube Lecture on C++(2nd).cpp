// Class-2 (If-Else)
// Hello , Everyone lets start our second class based on if- else .
// We just start our class based on 6 problems with solving conditions.
// First our topic is just start on if - else condition.
//Topics
// If(condition), Else If (Condition ), Else
// switch , case , default 
// Problem -1 
// Check voting eligibility
/*
#include<iostream>
using namespace std;
int main(){
    int age ;
    cout<<"Enter your age:";
    cin>>age;
    if(age>=18){
        cout<<"You are eligible of voting. Your voting age is : "<<age<<endl;
    }else{
        cout<<"You are not eligible of voting."<<endl;
    }
    return 0;
}
//Problem -2 
// Find Grade(A/B/C/F)
#include<iostream>
using namespace std;
int main(){
    int mark;
    cout<<"Enter your mark:";
    cin>>mark;
    if(mark>=80){
        cout<<"You got A grade."<<endl;
    }else if(mark<80&&mark>=70){
        cout<<"You got B grade."<<endl;
    }else if(mark<70&&mark>=60){
        cout<<"You got C grade."<<endl;
    }else {
        cout<<"You got F grade.";
    }
    return 0 ;
}
// Problem - 3 
// Check leap year
#include<iostream>
using namespace std;
int main(){
    int year;
    cout<<"Enter year:";
    cin>>year;
    if(year%4==0){
        if(year%100==0){
            if(year%400==0) cout<<year<<" is a leaf year.";
            else cout<<year<<" is not a leaf year.";
        }else{
            cout<<year<<" is a leaf year.";
        }
    }else{
        cout<<year<<" is not a leaf year.";
    }
}
// Pro - way 
// To solve leaf year problem.
#include<iostream>
using namespace std;
int main(){
    int year;
    cout<<"Enter year:";
    cin>>year;
    if((year%4==0&&year!=0)||(year%400==0)){
        cout<<year<<" is a leaf year.";
    }else{
        cout<<year<<" is not a leaf year.";
    }
}*/
// Problem - 4 
// Check divisible by 5 and 11 
#include<iostream>
using namespace std;
int main(){
    int digit;
    cout<<"Enter your digit:";
    cin>>digit;
    if(digit%5==0){
        cout<<"This digit is divisible by 5 .";
    }else if(digit%11==0){
        cout<<"This digit is divisible by 11. ";
    }
    return 0 ;
}



