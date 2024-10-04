#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
 int main(){


    
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    //Binary_search                            //Time__complexcity is equal to O(log(n));
    //just return 1 if the value present and 0 if the value not present
    // bool ans=binary_search(arr.begin(),arr.end(),30);
    // cout<<ans;

    //lower bound either return the value or just the greateer value than expected 35 i.e 40;
    // auto it=lower_bound(arr.begin(),arr.end(),40);
    // cout<<*it<<endl;

    //Upper bound only give the greater element in the answer
    // auto it= upper_bound(arr.begin(),arr.end(),40);
    // cout<<*it<<endl;


    //equal_range     homework :(


    //return iterator of greatest number form the array
    // auto it=max_element(arr.begin(),arr.end());
    // cout<<*it<<endl;

    //return the smallest element form thr array
    // auto it=min_element(arr.begin(),arr.end());
    // cout<<*it<<endl;

    return 0;
 }