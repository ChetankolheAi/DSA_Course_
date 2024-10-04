#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;

    //Pushing the vlues in the stack
    st.push(10);
    st.push(20);
    st.push(30);

    st.pop();
    
    stack<int> temp;


    //Method to print the stack value
    //we created temporary stack in which we just push the  top of the first stack named st after prinitng the top value
    while(!st.empty()){
        cout<<st.top()<<endl;
        temp.push(st.top());
        st.pop();
        
    }
    cout<<"Size after print"<<endl;
    cout<<st.size()<<endl;
    
    //here the value from the temp stack is reinserted in the main stack i.e st
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }


    //Checking the size of stack
    cout<<st.size()<<endl;
}