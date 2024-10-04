#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<vector<int>> arr(4, vector<int>(5,0));
    //the 2d vector is created with 5 rows and 4 column


    //to obtain the number of column in the 2D vector
    cout<<arr[0].size()<<endl;

    //To obtain the numbewr of roes in the 2D vector
    cout<<arr.size()<<endl;





    //to create the 2D vector with different number of column in every diffent row;
   vector<vector<int>> first(4);


    first[0]=vector<int>(2);
    first[1]=vector<int>(3);
    first[2]=vector<int>(5);
    first[3]=vector<int>(1);
    

    //to calculate the number of column in each row of the 2d vector
    cout<<"The size column in every rows in the 2d vector"<<endl;
    for(int i=0;i<first.size();i++){
        cout<<"Number of column in the row "<<i<< " is :- "<<first[i].size()<<" "<<endl;
    }
    return 0;
}