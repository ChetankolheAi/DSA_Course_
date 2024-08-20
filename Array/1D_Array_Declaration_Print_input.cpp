#include<iostream>
using namespace std;

int main(){
    int b[5];
    string a[5];
     for(int i=0;i<5;i++){
           b[i]=i+1;
        }
   cout<<"Enter thr 5 String data";
   for(int i=0;i<5;i++){
    cin>>a[i];
   }
    //print for b
    for(int i=0;i<5;i++){
        cout<<b[i];
    }
    //print for a;
    for(int i=0;i<5;i++){
        cout<<a[i];
    }
return 0;

}