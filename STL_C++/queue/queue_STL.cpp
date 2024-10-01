#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    
    deque<int>q;
    //Function to  push the value in the queue
    q.push_front(10);
    q.push_front(90);
    q.push_front(80);
    q.push_front(30);
    q.push_front(70);
    q.push_back(20);

    //Function to count the size of the queue;
    cout<<q.size()<<endl;

    //Function to pop the Value from the queue from the back/rear end;
    // q.pop_back();
    // q.pop_back();

    //to delete all the values from the queue
    // q.erase(q.begin(),q.end());

    //rechecking the size of deque after the erase function
    cout<<q.size()<<endl;

    //to print all the values of queue 
    deque<int>::iterator it=q.begin();
    while(it!=q.end()){
        cout<<*it<<"-";
        it++;
    }   
     

    //Randomly access the element
    //This function is available where the both the ends of data structurre or an array is open or we can insert the value in both the ends
    //lets take example of stack we can't randomly access the the element in the stack as stack is only one
    //sided open and also we  can not add value from both the ends
    cout<<"\nThe First element of the Doubly_Ended Queue is"<<endl;
    cout<<q[0]<<endl;
    
    

    //Reversing the queue using stack
    stack<int>s;
    for(int i=0;i<q.size();i++){
        s.push(q[i]);
    }
    int x=s.size();
    for(int i=0;i<x;i++){
        q.pop_front();
        q.push_back(s.top());
        s.pop();
    }
    // cout<<q.size()<<endl;

    //printing the queue after Reversing
    deque<int>::iterator it1=q.begin();
    while(it1!=q.end()){
        cout<<*it1<<"-";
        it1++;
    }   
     



}