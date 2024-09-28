#include<iostream>
using namespace std;

class stack{
    public:
    int* arr;
    int top;
    int size;
    
    stack(int capacity){
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

 };
int main(){
    stack s(5);
    

    s.push(10);
    s.push(30);
    s.pop();
    s.push(50);
    cout<<s.get_size();
    cout<<s.isempty();
    s.pop();
    s.pop();
    s.pop();




    s.Display();
    return 0;

}