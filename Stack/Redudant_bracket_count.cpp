#include<iostream>
#include<stack>
using namespace std;

int redundant_bracket(string s){
    stack<int>s1;
    int count =0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='+' ||s[i] == '-' ||s[i]=='/' ||s[i]=='*'){
            s1.push(s[i]);
        }
        else if(!s1.empty()){
            char top = s1.top();
            if(top == '(' && s[i] == ')'){
                s1.pop();
                count ++ ;
            }
            else if(top != '(' && s[i] == ')'){
                s1.pop();
                s1.pop();
            }
        }
        
    }
    return count;


}
int main(){


    int temp2 = redundant_bracket("((3)(+(+))(5))");
    cout<<"Count :- "<<temp2;

    return 0;
}