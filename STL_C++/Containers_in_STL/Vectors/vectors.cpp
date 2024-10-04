#include<iostream>
#include<vector>
using namespace std;




int main(){

    vector<int> marks;
    // vector<int> miles(10);
    // vector<int> disatance(15,0);


    //to insert the values in vector
    marks.push_back(10);
    marks.push_back(20);
    marks.push_back(30);

    //to check the number of element in the vector;
    cout<<marks.size()<<endl;

    //To remove the value from the vector;
    marks.pop_back();
    marks.pop_back();
    marks.pop_back();
    
    //to print thr first element form thr vector;
    cout<<marks.front()<<endl;

    //to print thr last element from the vector;
    cout<<marks.back()<<endl;
    

    //To check wheather thr vector is empty or not
    if(marks.empty()==true){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    
    //To print the first value of vector
    // cout<<*(marks.begin());

    

    return 0;

}