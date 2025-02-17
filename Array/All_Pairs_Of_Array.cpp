#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void PrintAllPairs(int arr[] , int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }

}
//Upper Triangle
void PrintAlltriangleUpper(int arr[] , int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }

}
//Down Triangle
void PrintAllDownTrianglePair(int arr[] , int size){
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            cout<<arr[i]<<","<<arr[j]<<endl;
        }
    }

}


//Three Sum
vector<vector<int>> ThreeSum(int arr[] , int size , int target){
    vector<vector<int>>ans;
    for(int i=0;i<size;i++){
        for(int j=i+1 ;j<size;j++){
            for(int k=j+1 ;k<size ;k++){

                if(arr[i]+arr[j]+arr[k] == target ){
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                }
            }
        }
    }
  
    for(int i =0;i<ans.size();i++){
        for(int j=0;j<3;j++){
            cout<<ans[i][j]<<",";
        }
       cout<<endl;
    }


}
int main(){
    int arr[6]={-1,0,1,2,-1,-4};
    int size = 6;
    // PrintAllPairs(arr, size);
    // PrintAllDownTrianglePair(arr , size);
    // PrintAlltriangleUpper(arr,size);

    int target = 0;
    ThreeSum(arr, size , target);
    
    return 0;
}
