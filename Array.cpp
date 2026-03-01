An array is a collection of elements stored in contiguous memory locations.
->Same data type
->Fixed size
->Access by index
->Fast lookup(O(1))
->Q1: Print all elements (Print using loop)

#include<iostream>
using namespace std ;
int main(){
    int n;
    cin>>n;
    int arr[n];
    //int arr[5]={1,2,3,4,5};
    //cout<<arr[2]<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//Q2: Sum of array
//Input N numbers -> print total sum
#include<iostream>
using namespace std ;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    cout<<"Total sum:"<<sum<<endl;
}

//Q3: Find largest number 
//->Find max element in array
#include<iostream>
using namespace std ;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    cout<<"Max Elements :"<<max<<endl;
}

//Q4: Count even numbers
//Count how many even numbers exist 
#include<iostream>
using namespace std ;
int main(){
    int n ;
    cin>>n;
    int arr[n];
    int counter = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            counter++;
        }
    }
    cout<<"Total even numbers :"<<counter<<endl;
}

//Q5: Reverse Array
// Input -> : 1 2 3 4 5 
// Output -> :5 4 3 2 1 
#include<iostream>
using namespace std ;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Original Array: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int left = 0;
    int right = n-1 ;
    while(left<right){
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        left++;
        right--;
    }
    cout<<"\nReverse Array:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    
}

//Q6: Linear Search
//->Check if element exists.
//->Input: 5 
//->Array: 10 20 30 40 50 
//->Search: 30
//->Output: Found 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int sc;
    cout<<"\nSearch: "<<endl;
    cin>>sc;
    // Implement a flag here 
    bool found = false ;
    for(int i=0;i<n;i++){
        if(arr[i]==sc){
            found = true ;
            break;
        }
    }
    if(found){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }   
}

//Q7: Insert element 
//-> Insert 25 at position 2 .
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Original Array :\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int value , pos;
    cout<<"\nInsert a Value:"<<endl;
    cin>>value;
    cout<<"Insert Position(0th index):"<<endl;
    cin>>pos;
    //Shift Right
    // We traverse right -> left
    //-> arr[4]=arr[3]
    //-> arr[3]=arr[2]
    //-> arr[2]=arr[1]
    for(int i=n;i>pos;i--){
       arr[i]=arr[i-1];
    }
    arr[pos]=value;//Insert Value 
    n++;//Increase Size
    cout<<"\nAfter insertion the value is :\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
//->When shifting right ->Loop backwards
//->when shifting left ->loop forwards

//Q8: Delete element
//->Remove element at given index.
#include<iostream>
using namespace std ;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Orginial array:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int pos;
    cout<<"Enter Index(0 starting index):";
    cin>>pos;
 
    if(pos<0||pos>=n){
        cout<<"Invalid Index"<<endl;
        return 0;
    }
    //Shift Left
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"After deletion the array is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}

//Q9. Second Largest Element 
//->Find 2nd max number 
#include<iostream>
#include<vector>
#include<climits>
using namespace std ;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest = INT_MIN;
    int second = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second = largest;
            largest = arr[i];
        }else if(arr[i]>second&&arr[i]!=largest){
            second = arr[i];
        }
    }
    if(second==INT_MIN){
        cout<<"Found second largest number"<<endl;    
    }else{
        cout<<"Not found second largest number "<<second<<endl;
    }
    return 0;
}

//Q10: Frequency of elements
//->Count how many ties each number appears
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        bool counted = false;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j]){
                counted = true;
                break;
            }
        }
        if(counted)continue;
        int count = 1;
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }

        }
        cout<<arr[i]<<"->"<<count<<endl;
    }
    return 0;
}

//Q11: Merge Two Array
#include<iostream>
using namespace std;
int main(){
    int n1 , n2 ;
    cout<<"First array size:"<<endl;
    cin>>n1;
    cout<<"Second array size:"<<endl;
    cin>>n2;
    int a[n1],b[n2],c[n1+n2];
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }
    for(int i=0;i<n1;i++){
        c[i]=a[i];
    }
    for(int i=0;i<n2;i++){
        c[n1+i]=b[i];
    }
    cout<<"\nMerge two arrays :\n";
    for(int i=0;i<n1+n2;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
