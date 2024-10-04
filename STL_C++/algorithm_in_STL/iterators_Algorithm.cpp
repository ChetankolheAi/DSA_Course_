#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// void printDouble(int a){
//     cout<<2*a<<" ";
// }

bool CheckEven(int a){
    return a%2 ==0;
}

int main(){

    vector<int> arr(5);
    arr[0]=7;
    arr[1]=1;
    arr[2]=1;
    arr[3]=3;
    arr[4]=3;

    //for each act like a loop where the operations is performed on every single element in the array 
    // for_each(arr.begin(),arr.end(),printDouble);
    
    // int target=30;
    // auto it = find(arr.begin(), arr.end(), target);
    // cout<<"\n"<<*it<<endl;

    //count the number of values that satisfy the condition in the target1 function
    // int ans= count_if(arr.begin(),arr.end(),CheckEven);
    // cout<<ans;

    //Function to sort the vector array 
    // sort(arr.begin(),arr.end());

    // reverse(arr.begin(),arr.end());
    //Method to print the array
    // for(int i:arr){
    //     cout<<i<<" ";
    // }


    //It is use to make partition of group on the basis of certain conditions
    //here i have check for the even and odd 
    //the partition is made like all the evene number is on left side and all the odd numbe are on right os iterator it
    // auto it=partition(arr.begin(),arr.end(),CheckEven);


    //the below block of code is use to remove the duplicate values from the array
    auto it= unique(arr.begin(),arr.end());
    arr.erase(it, arr.end());
    

    for(int i:arr){
        cout<<i<<" ";
    }


    

    return 0;


}