#include<iostream>
#include<list>
using namespace std;

int main(){

    //creation of list
    list<int> one;

    //add and element at the back
    one.push_back(10);
    //to add an element at the front
    one.push_front(90);

    //to remove the element from the back
    one.pop_back();

    //to remove an element from the front
    one.pop_front();

    
    one.push_back(20);

    //to print the size of the list
    cout<<one.size()<<endl;

    return 0;
}