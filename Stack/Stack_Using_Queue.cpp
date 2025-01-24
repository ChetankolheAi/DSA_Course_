#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int>q1;
    queue<int>q2;
    public:
    int size;
    stack(){
        size = 0;
    }
    

    void push(int val){
        q2.push(val);
        size ++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp;
        temp= q1;
        q1=q2;
        q2=temp;

    }

    void pop(){
        q1.pop();
    }
    int top(){
        return q1.front();
    }

};

int main(){

    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    int c= s.top();
    cout<<c;
    return 0;


}
