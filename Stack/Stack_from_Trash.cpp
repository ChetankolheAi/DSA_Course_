#include<iostream>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

class stack1{
    public:
    int* arr;
    int top;
    int size;

    
    stack1(int capacity){
        arr= new int[capacity];
        size=capacity;
        top=-1;
        for(int i=0;i<size;i++){
            arr[i]=-1;
        }
     }
     


void push(int val){
    if(top==size-1){
        cout<<"\nstack is full"<<endl;

    }
    top++;
    arr[top]=val;

}
void pop()
{
    if(top==-1){
        cout<<"\nthe stack is empty"<<endl;
        return ;

    }
    else{
        arr[top]=-1;
        top--;
    }

}
bool isempty(){
    
    if(top==-1){
        return true;
    }
    else{
        return false;
    }

}
int get_size(){
        int x=top+1;
        return x;
 }

 int get_top(){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else{
        return arr[top];
    }
    
 }

 void Display(){
    if(top!=-1){
        cout<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
    }
 }
 
 //ye  mere vala check sorted function se aapna data loss nahi hoga lekin 
 //Love babber k video 2 of stack  k code se data bhi loss ho jayega ->>
 void check_sorted(int temp1 ,stack<int>& s1){
    
    //in temp1 we have define INT_MAX in first condition after that if temp2 is less than temp 1 then the value of 
    //temp2 is assign to temp1 and this continues till top becomes -1  or any where condition fails  
    int temp2 = arr[top];

    if(temp2<temp1){

        s1.push(arr[top]);

        top = top -1;

        if(top == -1){

            cout<<"The Stack is Sorted"; 

            for(int i =0;i<s1.size();i++)
            {
                push(s1.top());
                s1.pop();
            } 
            return;
        }
        check_sorted(temp2,s1);

    }
    else{
        cout<<"The Stack Is Not sorted";
    }




 }

 
 
 };
int main(){
    stack1 s(5);
    

    s.push(10);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    stack<int> s1;
    s.check_sorted(INT_MAX,s1);




    s.Display();
    return 0;

}