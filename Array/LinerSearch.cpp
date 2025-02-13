#include<iostream>
#include<limits.h>
using namespace std;


//linear Search 
bool findTraget(int arr[] , int size , int target){
    for (int  i = 0; i < size; i++){
        if(arr[i] == target){
            return true;
        }
    }
    //agar yaha tak pahuc gaye matlab targeted element array k aandar nahi h
    //return false kar do
    return false;
    
}

//maximum Number Find KArne k liye Function
int maxi(int arr[] , int size){
    int max1 =   INT_MIN;  //or  arr[o]   //or  0 ;
    for(int i =0 ; i < size ; i++){
        if(arr[i]>max1){
            max1 = arr[i];
        }

    }
    return max1;

}

//Minium Number Find KArne k liye Function
int mini(int arr[] , int size){
    int mini1 =   INT_MAX;  //or  arr[o]   //or  0 ;
    for(int i =0 ; i < size ; i++){
        if(arr[i]<mini1){
            mini1 = arr[i];
        }

    }
    return mini1;

}

//Count number of 0's and 1's 
int count0nd1(int arr[] , int size){
    int count0 = 0;
    int count1=0;
    for( int i =0;i<size ;i++){
        if(arr[i] == 0){
            count0+=1;

        }
        else if(arr[i] == 1){
            count1+=1;
        }
    }
    cout<<"O Count is :- "<<count0<<endl;
    cout<<"1 Count is :- "<<count1<<endl;;
}

//Extream Element Printing Using 2 Pointer
void twoPointer(int arr[] , int size){
    int i =0;
    int j = size -1;
    while(j >= i){
        cout<<arr[i]<<endl;
        if(i==j)break;
        i++;
        cout<<arr[j]<<endl;
        j--;
    }
}


//Reverse Array Using 2 Pointer
int* ReverseArray(int arr[] , int size){
    int i = 0;
    int j = size-1;
    
    while(i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return arr;
    
}

//Find The Number Which Occurs Only Once In Arrys 
//Vo yek element Chod k sab 2 bas aaye h 
void  findSingleElement(int arr[] , int size){
    int ans =0;
    for( int i=0;i<size;i++){
        ans = ans ^ arr[i];

    }
    cout<<endl;
    cout<<ans;
}

int main(){
   
    int arr[5] = {1,1,2,3,2};
    int size = 5;
    int target = 78;

    //Find Target
    int ans = findTraget(arr , size , target);
    if(ans)
        cout<<"The Target Found"<<endl;
    else
        cout<<"The Target Not Found"<<endl;

    //Find MAX
    int max = maxi(arr , size);
    cout<<"The Maximum Number From The List Is := "<<max<<endl;

    //Find MIN
    int min = mini(arr , size);
    cout<<"The Minimum Number From The List Is := "<<min<<endl;

    count0nd1(arr ,size);
    twoPointer(arr ,size);

    int* Reversearr = ReverseArray(arr, size);
    for(int i=0;i<size;i++){
        
        cout<<Reversearr[i];
    }


    
    findSingleElement(arr , size);
    return 0;
}