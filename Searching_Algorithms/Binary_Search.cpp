#include<iostream>


using namespace std;

    int mountain_array(int arr[], int n){
        int temp = -1;
        int start = 0;
        int end = n-1;
        int mid = start+(end-start)/2;
        while(start<end){
            if(arr[mid]<arr[mid+1]){
                
                start = mid +1;
            }
            else{
                end= mid;
                
            }
            mid = start+(end-start)/2;
        }
        return mid;

    }

    int first(int arr[],int n , int target){
        int temp = -1;
        int start = 0;
        int end = n-1;
        int mid = (start+end)/2;//alternet formula   start+(end-start)/2;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]==target){
                // cout<<"Target Found :"<<target<<" at the Index:- "<<mid<<endl;
                // break;
                temp = mid;
          
                end = mid-1;
            }
            if(arr[mid]<target){
                start= mid+1;
            }
            else if(arr[mid]>target){
                end = mid-1;
            }
        }
 
        return temp;
    

    }
    int second(int arr[], int n , int target){
        int temp = -1;
        int start = 0;
        int end = n-1;
        int mid = (start+end)/2;//alternet formula   start+(end-start)/2;
        while(start<=end){
            int mid = (start+end)/2;

            if(arr[mid]==target){
                // cout<<"Target Found :"<<target<<" at the Index:- "<<mid<<endl;
                // break;

                temp = mid;

                start = mid + 1;
            }
            if(arr[mid]<target){
                start= mid+1;
            }
            else if(arr[mid]>target){
                end = mid-1;
            }
        }
        
        return temp;
    

    }
int main(){
    int target = 5;
    int arr[8]= {1,2,3,4,9,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int first_index = first(arr,n ,target);
    // int last_index = second(arr,n, target);

    int index = mountain_array(arr,n);
    cout<<index;
    // if(first_index != -1 && last_index != -1){
        
    //     cout<<"Your Target "<<target << " is Occured "<<(last_index-first_index)+1<<" times";
    // }
    // else
    // {
    //     cout<<"No Element Found"<<endl;
    // }
        


    return 0;


}