#include<iostream>
#include<map>
using namespace std;

int main(){


    //Method 01 of insertion the key value pair in the map
   map<string, string>mp;
   mp["in"]="INDIA";
   mp["ch"]="CHINA";

    //Method 02 of insertion of the key value pair in the map
   pair<string,string>p1;
   p1.first="br";
   p1.second="BRAZIL";
   mp.insert(p1);

   //Methjod of 03 of insertion of the keyy value pair in the map
   mp.insert(make_pair("en","ENGLAND"));

    //Creation of 2nd map to use swap function
    map<string,string>mp1;
    mp1["ch"]="CHETAN";

    //Swapping the value of map1 with map2
    mp.swap(mp1);

    //Function to erase all the values from the map , mp;
    // mp1.erase(mp1.begin(),mp1.end());


    //To check whether the key is present in the map or not
    if(mp.count("ch")==0){
        cout<<"Key Not Found"<<endl;
    }
    else if(mp.count("ch")==1){
        cout<<"Key Found"<<endl;
    }
    

    if(mp.find("ch")!=mp.end()){
        cout<<"Key Found"<<endl;

    }
    else if(mp.find("ch")==mp.end()){
        cout<<"Key Not Found"<<endl;
    }
   
    //Method to print the key value pair from the map using iterator
   map<string,string> ::iterator it = mp1.begin();
   while(it!=mp1.end()){
        pair<string,string> p=*it;
        cout<<p.first<<" "<<p.second<<endl;
        it++;

   }
     
    cout<< mp.size()<<endl;
    cout<<mp1.size()<<endl;


    return 0;
} 