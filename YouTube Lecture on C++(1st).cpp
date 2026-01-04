   // Hello Everyone , Welcome to Alone Space Youtube Channel
   // So , Today Basically we will learn about the basics of C++ programing .
   // Althought its a primary language those who are target to get a job in Google.
   // Lets start 
   // First Code ("Print Hello World ")
   // So , My First target is to use to each and every aspect of learning C++ line by line Explanation.
   /*
   #include<iostream>//(#include) importing toolbox. (iostream)Input / Output Stream .

   using namespace std ;//(This tells the computer we are using standard library . It saves us from using (std::cout) );
   int main(){
    cout<<"Hello World !"<<endl;// cout(Character Output)
    return 0 ;
   }*/
    // This is all we learn about our first Code .
    // Second Code (Variables and Types )
    // So , you guys have to learn about all the baiscs important thing and u should have to remember this for code input / output .
   /*
    #include<iostream>
    using namespace std ;
    int main(){
      int a ; //(int = Interger )
      float b ;//(float = Small Decimal Like it will take 7 decimal digits )
      double c ;//(double = Large Decimal Like it will take 15 to 16 decimal digits )
      char d ; //(char = character It will a single words like a , b & c etc)
      string e ; //(string = text It will take all full text . However a single texts only )
      // Now we have time to input this variables in different variable box.
     // cout (for print )& cin (for taking values )
     //Input & Output
     //So our input & Output is done 
      cout<<"Enter a integer digit : ";
      cin>>a ;
      cout<<"Ënter a small decimal values:";
      cin>>b;
      cout<<"Enter a large decimal values:";
      cin>>c;
      cout<<"Enter a single alphabet: ";
      cin>>d;
      cout<<"Enter a Single name: ";
      cin>>e ;
      // Now , we have time to print this code .
      cout<<a<<endl;//endl so that our output looks clean .
      cout<<b<<endl;
      cout<<c<<endl;
      cout<<d<<endl;
      cout<<e<<endl;
      return 0 ;

    }*/
    // Now , I would go our next step like prefix and postfix increament .
    //Prefix Increment(++a)
    // Increament first , then use.
    //Postfix Increment(a++)
    // Use first , then increment .
    // First , Prefix Code
    /*
    #include<iostream>
    using namespace std;
    int main(){
      int a ;
      cout<<"Enter your first digit:";
      cin>> a;
      cout<<++a<<endl;
      return 0;
    }*/ 
    // This is our prefix code 
    // Now , we just learn a simple postfix code.
    /*
    #include<iostream>
    using namespace std ;
    int main(){
      int a ;
      cout <<"Enter your first digit:";
      cin>>a ;
      cout<<(a++)<<endl;
      cout<<a<<endl;
      return 0 ;
    }
    // Now , we just learn about some simple mathematics .
    // Like sum , divide etc .
    // Like simple calculator math.
   */
  /*
  #include<iostream>
  using namespace std;
  int main(){
   int a , b ;
   cout<<"Enter two digit (a&b):";
   cin>>a>>b;
   cout<<(a+b)<<endl;
   cout<<(a-b)<<endl;
   cout<<(a/b)<<endl;
   cout<<(a%b)<<endl;
   return 0 ;
  }*/
 // Now , we just learn about increment and decrement ;
 //Increament
 /*
 #include<iostream>
 using namespace std ;
 int main(){
   int a ;
   cout<<"Enter your first digit :";
   cin>>a ;
   cout<<(a++)<<endl;
   cout<<a<<endl;
   return 0 ;
 }
 // Decreament 
*/
/*
#include<iostream>
using namespace std;
int main(){
   int a ;
   cout<<"Enter your first digit :";
   cin>>a ;
   cout<<(a--)<<endl;
   cout<<a<<endl;
   return 0 ;
}*/
// So guys i done all of simple progrming for C++
// Lets solve a begnner level problem
// Question : Swap Two Numbbers 
// so now solve this question by youurself . Pa\use the vedio and try .
#include<iostream>
using namespace std ;
int main(){
   int a , b ;
   cout<<"Enter two digit(a&b) :";
   cin>>a>>b ;
   // a simple rule we apply .
   // 1 st create a temp box and then put a value in that box .
   // then transfer a value to b value 
   // then b value is temp
   int temp = a;
   a=b;
   b= temp;
   cout<<b<<endl;
   return 0 ;
} 
// Now todays thats all . In the next vedio see you guys .
// GOOD NIGHT .
// STAY HEALTHY











