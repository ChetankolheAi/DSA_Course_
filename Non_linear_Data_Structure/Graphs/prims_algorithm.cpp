#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;

class Graphs{
    public:
    unordered_map <int, list<pair<int,int>>> maplist;

    void add (int a , int b ,int w, bool Directed){
        //if directed then 1 else 0
        if(Directed){
            maplist[a].push_back({b,w});
        }
        else{
            maplist[b].push_back({a,w});
            maplist[a].push_back({b,w});
        }
    }

    void display(int n){
         for(int i=0;i<n;i++){
            cout<<i<<":";
            cout<<"{";
          
            for(auto i: maplist[i]){
                cout<<i.first<<",";
            }
            cout<<"}"<<endl;
         }
    }


    //ye to bas index of minimum value  find karne k liye function h;;

    int getMiniumValueNode(vector<int>& Key ,vector<bool>& Visited){

        int temp = INT_MAX;
        int index = -1;
        for(int i=0;i<Key.size();i++){ 

            if(Key[i] < temp && !Visited[i]){
                temp = Key[i];
                index = i;
            }
            
        }
        cout<<index;
        return index;

    }
    void prims_algo(int src , int n){

        vector<bool>Visited(n,false); // ye store karega ki Node pehele se hi visited h ya nahi 
        vector<int> Key(n, INT_MAX);// ye Minimum value of weigth carry karega to the respective parent
        vector<int> parent(n, -1);  // ye parent store karega // agar yek node k 2 ya 4 parent hoge to vo fir smallest weight vala hi parent store karega

   
        Key[src] = 0;
     

        while(true){

            // u will contain the smallest value index from Key vector;

            int u = getMiniumValueNode(Key , Visited);

            //if the function "getMiniumValueNode" return  -1 that means all the nodes are visited and we need to stop executing this loop
            if(u == -1){
                break;
            }

            //mark node visited true
            Visited[u] = true;
            

            //basic : - the first value is node and second is weight
            for(auto nbr : maplist[u]){
                int node = nbr.first;
                int weight = nbr.second;

                //ye step important hey
                //aagr Key(vector) ka element at index node  Bada he node k weight se (i.e  Key[node]>weight ) then node ka weight insert kar do Key(vector) me at index node;
                //where this node is neighbour of u ;

                if(Key[node]>weight && Visited[node]==false){

                    Key[node] = weight;

                    //weight miniumn h to uske bap ko parent vector me store kar do
                    parent[node]=u;

                }
            }
        }

        //ye to basic logic h sum of arrray karne k liye

        //humne parent.size() liya h aap konsa bhi vector le sakte ho no problem
        int ans =0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]!= -1){
                ans = ans + Key[i];
            }

        }


        
        //Simple Printing the Miniumn Weight of Spanning Tree 
        cout<<"The Minium Spanning tree of Weight is :- "<<ans<<endl;
        
        

    }

    
};
int main(){

    Graphs g;
    g.add(0,1,2,0);
    g.add(1,2,3,0);
    g.add(1,4,5,0);
    g.add(1,3,8,0);
    g.add(0,3,6,0);
    g.add(2,4,7,0);
    g.prims_algo(0,5);
    
    return 0;
}