// 1.Factorial Using Recursion
// Definition -->n! = n*(n-1)*(n-2)*....*1
// 5! = 5*4*3*2*1 = 120
// 5! = 5 * (n-1) * (n-2) * .... * 1 
/*
#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0||n==1){// Base Case
        return 1 ;
    }else{
        return n * factorial(n-1);//Recursive Case
    }
}
int main(){
    cout<<factorial(5);
}

// 2. Convert Decimal --> Binary(toBinary)
// Example: 13->1101
// 13/2 -> remainder 1 
// 6/2  -> remainder 0
// 3/2  -> remainder 1 
// 1/2  -> remainder 1 
#include<iostream>
using namespace std;
void toBinary(int n){
    if(n==0){
        return;
    }
    // binary (n) = binary(n/2)+n%2
    toBinary(n/2);
    cout<<n%2;
}
int main(){
    toBinary(13);
}

// 3. Calculate a^b (Power)
// Recursive Formula a^b = a * a^(b-1)
#include<iostream>
using namespace std;
//int power(int a , int b){
    //if(b==0){
        //return 1 ;
    //}else{
        //return a * power(a,b-1);
    //}
//}
int fastPower(int a , int b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        int half = fastPower(a,b/2);
        return half*half;
    }
    else{
        return a* fastPower(a,b-1);
    }
}
int main(){
    //cout<<power(2,5);
    cout<<fastPower(2,5);
}
*/
// 4. Fibonacci Series
// F(n)=F(n-1)+F(n-2)
// 0 1 1 2 3 5 8 13 21 
#include<iostream>
using namespace std;
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    cout<<fibonacci(7);
}

