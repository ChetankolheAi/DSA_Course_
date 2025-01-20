#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

//ye function to bas display karega answer ko (i.e vector v ko display karega)
void display(vector<int>&v,int n){


    cout<<"The Answer is :- " ;
    for(int i=0;i<n;i++){
        
        cout<<v[i]<<" ";
    }

}

//this find the first smallest previous element from the Arry or list
void find_privous_smaller_element(int arr[],int n,stack<int>& s,vector<int>&v){
    for(int i=0;i<n;i++){

        //while loop ka kam he aagar top of stack element aagr bada h arr[i] se to pop karo vo element till koyi chota element na aajaye stack k top k upar
        while(arr[i]<s.top()){
            s.pop();
        }

        //jaise hi chota element stack k top k upar aaya ki vo vector(i.e answer array) k andar push kar do
        //aaur arr[i] ko stack k andar push kar do
        if(arr[i]>s.top()){
            v.push_back(s.top());
            s.push(arr[i]);

        }
    }
    
    display(v,n);
}
void find_next_smaller_element(int arr[],int n,stack<int>& s,vector<int>&v){
    for(int i=n-1;i>=0;i--){

        //while loop ka kam he aagar top of stack element aagr bada h arr[i] se to pop karo vo element till koyi chota element na aajaye stack k top k upar
        while(arr[i]<s.top()){
            s.pop();
        }

        //jaise hi chota element stack k top k upar aaya ki vo vector(i.e answer array) k andar push kar do
        //aaur arr[i] ko stack k andar push kar do
        if(arr[i]>s.top()){
            v.push_back(s.top());
            s.push(arr[i]);

        }
    }
   
    display(v,n);
}
int main(){
    int arr[] ={2,4};
    stack<int>s;
    int n =2;
    vector<int>v;
    s.push(-1);
    find_privous_smaller_element(arr,n,s,v);
   
    find_next_smaller_element(arr,n,s,v);

    return 0;
}