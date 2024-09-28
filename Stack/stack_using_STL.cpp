#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    //insertion of values in stack
    s.push(10);
    s.push(20);
    s.push(30);

    //poping of top value from the stack
    s.pop();

    //to check the size of the stack
    cout<<s.size()<<endl;

    //to check wheather the stack is empty or not
    cout<<s.empty()<<endl;
    
    //to get the top element from thr stack
    cout<<s.top()<<endl;



}