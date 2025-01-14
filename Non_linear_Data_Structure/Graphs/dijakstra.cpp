#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>
#include<set>
using namespace std;
 class Graph{

    public:
    unordered_map<int,list<pair<int,int>>> Maplist;
    void add_node(int i , int j , int k , bool Directed){
        if(Directed){
            Maplist[i].push_back({j,k});
        }
        else if(!Directed){
            Maplist[i].push_back({j,k});
            Maplist[j].push_back({i,k});
        }
    
    }
    void Display(int n){
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<"{";
            for(auto j: Maplist[i]){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }
            cout<<"}"<<endl;

        }
    }

    void Shosrtest_distance_dijkstra(int src,int n){
        vector<int> dist(n+1 , INT_MAX);
        set <pair<int,int>> st;

        dist[src]=0;
        st.insert({0,src});

        while(!st.empty()){
             
             auto topElement = *(st.begin());  //fetch the top pair form the set // that why we use auto keyword as the pair is not an interger so we cant use int here as data type
             
             
             int topNodeDistance = topElement.first;//fetching the first element "i.e Distance " of the pair in set
             int topNode =  topElement.second;//fetching the secomnd element  of the pair from the set

             //pop ths node after fetching

             st.erase(st.begin());

             //neighbour per jao bhai 
             for(auto nbr: Maplist[topNode]){
                //nbr = {a,b}
                //a->node;
                //b->weight


                int nbrNode = nbr.first;
                int nbrNodeDistance = nbr.second;

                if(dist[topNode] + nbrNodeDistance < dist[nbrNode]  ){

                    //2 kam karo bhai fir

                    //1. Distance arrray ko update kro 
                    //2.set ko update karo

                    auto result = st.find({dist[nbrNode],nbrNode});
                    //ye  "st.find( )"  yek iteratoor return karta h isliye 
                    //hum check karenge ki search karte karte last value tak to nahi pahucha 
                    //agar last value tak pahuc gaya matlab jp vaule hum dhud rahe the vo present nahi he set me
                    if(result != st.end()){

                        // entery mil gayi he aaur vo entry delete karo aaur dusari entry dalo "less path value wali"
                        st.erase(result);
                    }
                    dist[nbrNode] =  dist[topNode]+ nbrNodeDistance;
                    st.insert({dist[nbrNode],nbrNode});
                }

             }

        }
        cout<<"distance :- "<<endl;
        for(int i=1;i<=5;i++){
            cout<<"Distance From 0 to "<<i<<" is :- "<<dist[i]<<endl;
        }

    }
   
 };
 int main(){
    Graph g;
    g.add_node(1,2,7,0);
    g.add_node(1,3,1,0);
    g.add_node(3,5,7,0);
    g.add_node(3,4,2,0); 
    g.add_node(2,4,3,0);
    g.add_node(4,5,6,0);
   
    g.Shosrtest_distance_dijkstra(1,5);
    return 0;
 }