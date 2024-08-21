#include<iostream>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;

    }
}
void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;

    }
}
void pattern3(int n){
    for(int i=0;i<n;i++){

            for(int k=0;k<i;k++){
                cout<<"  ";
                
            }
            for(int j=0;j<n-i;j++){
                cout<<"* ";
             }
             cout<<endl;
        }
        

}

void pattern4(int n){
    for(int i=0;i<n;i++){

        for(int j=n ;j>i;j--){
            cout<<"  ";
        }
        for(int k=0;k<i+1;k++){
            cout<<"* ";
        }
        cout<<endl;
        

    }
}


void pattern5(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"* ";
        }
        cout<<endl;

    }
}

void pattern7(int n){
    for(int i=0;i<n;i++){

        for(int j=n ;j>i;j--){
            cout<<"  ";
        }
        for(int k=0;k<i+1;k++){
            cout<<k+1<<" ";
        }
        cout<<endl;
        

    }
}

void pattern6(int n){
    int count=1;
    int count1=count;
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            
            cout<<count<<" ";
            count++;
        }
        count1++;
        count=count1;
        cout<<endl;
    }
}

int main(){


    //20.08.2024
    int choice;
    cout<<"Enter the pattern Number :- 1 to 9 "<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        pattern1(5);
        break;
        case 2:
        pattern2(5);
        break;
        case 3:
        pattern3(5);
        break;
        case 4:
        pattern4(5);
        break;
        case 5:
        pattern5(5);


        //21.08.2024
        break;
        case 6:
        pattern6(5);
        break;
        case 7:
        pattern7(5);
        break;
        default:
        cout<<"Enter the correct choice"<<endl;

    }
    
    ;
}