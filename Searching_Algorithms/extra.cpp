#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> a(8);
    a[0]=9;
    a[1]=3;
    a[2]=2;
    a[3]=8;
    a[4]=4;
    a[5]=1;
    a[6]=5;
    a[7]=7;

    int n= a.size()+1;
    vector<bool> arr(n,false);
   
    for( int i=0;i<a.size();i++){
        arr[a[i]] = true;
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i]== false){
            cout<<"the Missing Number is:- "<<i<<endl;
        }
    }
   


    return 0;
}