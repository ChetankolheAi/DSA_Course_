#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(){

    vector<int> arr(5);
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    arr[3]=40;
    arr[4]=50;


    //accumulater is use to calculate the sum of all the element of the vector array
    //here 0 is the initial value
    // int ans=accumulate(arr.begin(),arr.end(),0);
    // cout<<ans;

    //inner producrt first multiple the every value at same index form the 2 array and then  add aal the answer to give final one
    //for eg:
    // vector<int> first;
    // first.push_back(1);
    // first.push_back(2);
    // first.push_back(3);
    // vector<int> second;
    // second.push_back(3);
    // second.push_back(4);
    // second.push_back(5);
    // int ans1= inner_product(first.begin(),first.end(),second.begin(),0);
    // cout<<ans1;

    //This gives the sum of partial elemnet till the last one i.e  it will calculate 1+2 then(1+2)+3 then ((1+2)+3)+4)  1234 are the indexex
    // vector<int>ans(arr.size());
    // partial_sum(arr.begin(),arr.end(),ans.begin());
    // for(int a:ans){
    //     cout<<a<<" ";
    // }
    

    //iota us eto insert the incremental values in the array 
    // vector<int> temp(10);
    // iota(temp.begin(),temp.end(),2500);
    // for(int i: temp){
    //     cout<<i<<" ";
    // }


    return 0;
}