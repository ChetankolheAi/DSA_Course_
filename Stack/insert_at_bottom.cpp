#include<iostream>
#include<stack>
using namespace std;

void Insertatbottom(stack<int>&s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int topcopy=s.top();
    s.pop();

    Insertatbottom(s,val);

    s.push(topcopy);
}

 int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(70);
    s.pop();
    Insertatbottom(s,45);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    return 0;

 }
