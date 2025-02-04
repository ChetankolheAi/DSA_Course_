#include<iostream>
using namespace std;

    int factorial(int n){

        //handling base case for recursion
        if(n == 0){
            return 1;
        }

        //Now just if we want to find the factorial of 7 
        // 7! = 7 * 6!;
        //therefore 
        // ans = n * factorial(n-1);

        //Now here factorial(n-1) is recursive call to the fuctionn to find the factorial of 6

        int ans = n * factorial(n-1);

        //here the recursion will go on till the base case is reached and then return back the value till the ans variable of the function 
        //Some Question like find the power of number is also Done by recursion

        //
    }
 int main(){

    int n ;
    cout<<"Enter the number whosee fctorial you want to find ";
    cin>>n;

    int ans = factorial(n);
    cout<<"The Factorial of "<<n<<" = "<<ans;


    return 0;
 }