
//Q14 : Write a program to calculate
//->square rot
//->power
//->absolute value
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<sqrt(4)<<endl;
    cout<<pow(2,3)<<endl;
    cout<<abs(3.141638393838)<<endl;
}

//Q15: Write a program that finds distance between two points
// distance sqrt((x2-x1)^2+(y2-y1)^2)
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int x1 , x2, y1 ,y2;
    cin>>x1>>x2>>y1>>y2;
    cout<<sqrt(pow((x2-x1),2)+pow((y2-y1),2))<<endl;
}

//Q16: Write a program to find largest and smallest number using min() and max()
#include<iostream>
#include<cmath>

using namespace std;
int main(){
     int a , b ,c ;
     cin>>a >>b>>c;
     cout<<"Max = "<<max(a,max(b,c))<<endl;
     cout<<"Min = "<<min(a,min(b,c))<<endl;
     
}
