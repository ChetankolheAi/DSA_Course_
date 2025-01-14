/// Ye Kosaraju algorithm use hota h strongly connected component find out karne k liye
/// Means we can say that number of island in the graph
/// Topological sort karna  is must in this algorithm 

//hum yek naya map banayenge aaur fir vo naye map ko use karke uska DFS nikalenge
#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

class Graphs{
    public:
    unordered_map <int, list<int>> maplist;

    void add (int a , int b , bool Directed){
        //if directed then 1 else 0
        if(Directed){
            maplist[a].push_back(b);
        }
        else{
            maplist[b].push_back(a);
            maplist[a].push_back(b);
        }
    }

    void display(int n){
         for(int i=0;i<n;i++){
            cout<<i<<":";
            cout<<"{";
            list<int> temp = maplist[i];
            for(auto i: temp){
                cout<<i<<",";
            }
            cout<<"}"<<endl;
         }
    }
    

    void topoSort(stack<int>& s, int node , unordered_map<int, bool> & vist){

        vist[node]=true;
        for(auto nbr: maplist[node]){
            if(!vist[nbr]){
                topoSort(s,nbr,vist);
            }
        }
        s.push(node);

    }
    void dfs(int src , unordered_map<int,bool>& visit, unordered_map<int,list<int>>& maplist_new){
    
        visit[src]= true;

        for(auto neighbour: maplist_new[src]){
            if(!visit[neighbour]){
                dfs(neighbour,visit,maplist_new);
            }
        }

    }

    int CountSCC(int n){
        //Step 1 Find TopoOrdering
        stack<int> s;
        unordered_map<int,bool>vist;

        for(int i =0;i<n;i++){
                if(!vist[i]){
                    topoSort(s,i,vist);
                }
        }


        //step2: reverse all the edges 
        unordered_map<int,list<int>> maplist_new;
        for(auto i: maplist){
            for(auto j : i.second){
                int u = i.first;
                int v = j;

                //u->v eke edge thi , and muje reverse karna h 
                //iska matlab v->u edge banani h

                maplist_new[v].push_back(u);
            }
        }

        //traversal
        int count =0;
        unordered_map<int,bool> visit;
        
        while(!s.empty()){
            int src = s.top();
            s.pop();

            if(!visit[src]){
                dfs(src,visit,maplist_new);
                count++;
            }
        }
        return count;
    }
};
int main(){

    Graphs g;
    g.add(0,3,1);
    g.add(3,2,1);
    g.add(2,1,1);
    g.add(1,0,1);
    g.add(2,4,1);
    // g.add(4,5,1);
    // g.add(5,6,1);
    // g.add(6,4,1);
 
    g.display(3);
   int n;
   cout<<"Enter the number of nodes"<<endl;
   cin>>n;
    
    //yaha par TopoSort Ready h 
    int h =g.CountSCC(n);
    cout<<"SCC count : "<<h<<endl;

    // cout<<"Printing toposort : -"<<endl;
    // while(!s.empty()){
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }
    return 0;
}