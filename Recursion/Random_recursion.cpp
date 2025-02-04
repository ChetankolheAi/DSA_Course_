#include<iostream>
using namespace std;



void printAllEvenFromArray(int arr[] , int size , int i){
    if(i == size) return ;

    if(arr[i]%2 == 0) cout<<arr[i]<<"_";
    printAllEvenFromArray(arr ,size , i+1);
}
//to print all odd elemet form the array using rcursionn 
void printAllOddsFromArray(int arr[], int size , int i){
    if(i == size) return;

    if(arr[i]%2 != 0) cout<<arr[i]<<"_";
    printAllOddsFromArray(arr , size , i+1);
}

//find thr Minimumnelement in thr array using recursion 
void miniInArray(int arr[] , int size , int &ans , int i){
    if(i ==  size)
        return ;
    
    if(arr[i] < ans)
        ans = arr[i];
    
    miniInArray(arr, size, ans , i+1);

    
}

//recursion use kar ke hum array print kiye he
void printArray(int arr[],int size, int i){
    if(i == size)
        return;
    cout<<arr[i] <<"_";
    printArray(arr,size , i+1);
}

//recursion se hum sum bhi nikal sakate hai
int summesion(int n){

    //just think of how we can do it
    //summesion of 5 = summession of4 + 5
    if(n==1){
        return 1;
    }

    //therefore
    int ans = n + summesion(n-1);
    return ans;
}

int fibonacci(int n){
    

    //First We need to handle the base case for the recursion
    // The Base Case for this question is if n = 0 or n = 1 then the fibonacci number will be 0 and 1 respectively

    if(n==0 || n==1){
        return n;
    }

    //now we know that the fibonacci number is the sum of the previous two fibonacci numbers
    //therefore fib(4) = fib(4-1) + fib(4-2);
    //i.e

    int ans = fibonacci(n-1) + fibonacci(n-2);

    //this will print only the last fibonacci number
    //Not the whole series 
    return ans;

}

int main(){

    // int ans = fibonacci(7);
    // cout<<"The Required Fibonacci Number IS :-  ";
    // cout<<ans<<endl;

    // int summesion1 = summesion(5);
    // cout<<"The Required Summesion is :- ";
    // cout<<summesion1;
    int size = 5;

    int arr[5] = {45,20,43,40,1};
    int i =0;
    int ans  =  arr[0];
    miniInArray(arr, size , ans , i);
    cout<<"The Minimum element in thr array is :- " <<ans <<endl;;


    printAllOddsFromArray(arr, size ,i);
    cout<<endl;
    printAllEvenFromArray(arr , size , i);
    return 0;
}