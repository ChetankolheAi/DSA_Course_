#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
   vector<int> result;
    vector<int> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);
    first.push_back(4);
    first.push_back(5);

    vector<int> second;
    second.push_back(3);
    second.push_back(4);
    second.push_back(5);
    second.push_back(6);
    second.push_back(7);
    
    //Remove Duplicate values
    // set_union(first.begin(),first.end(),second.begin(),second.end(),inserter(result,result.begin()));
    // for(int i: result){
    //     cout<<i<<" ";
    // }

    

    ///gives common values
    //  set_intersection(first.begin(),first.end(),second.begin(),second.end(),inserter(result,result.begin()));
    //  for(int i: result){
    //     cout<<i<<" ";
    // }

      set_difference(second.begin(),second.end(),first.begin(),first.end(),inserter(result,result.begin()));
       for(int i: result){
        cout<<i<<" ";
    }




    return 0;
}