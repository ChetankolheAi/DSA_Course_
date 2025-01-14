#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>
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

    void shortest_path(int source , int destination){
        
        queue<int> q;
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        q.push(source);
        visited[source]=true;
        parent[source]=-1;

        while(!q.empty()){

            int Frontnode=q.front();
            q.pop();


            for(auto neighbour : Maplist[Frontnode]){

                int node= neighbour.first;
                int weight = neighbour.second;
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                    parent[node]=Frontnode;
                }
            }

        }

        vector<int> path;

        int node = destination;
        while(node!=-1){
            path.push_back(node);
            node= parent[node];

        }

        reverse(path.begin(),path.end());

        for(auto i : path){
            cout<<i<<"->";
        }
    
    }
    // void toposort(int src , unordered_map<int , bool>& visited, stack<int>& ans){
    //     visited[src]=true;
    //     for(auto neigh: Maplist[src]){
    //         if(!visited[neigh.first]){
    //             toposort(neigh.first,visited,ans);
    //         }
    //     }
    //     ans.push(src);
    // }
    // void shortest_path_dfs(int src){
    //     stack<int> toploorder;

    //     unordered_map<int,bool>visited;

    //     toposort(src,visited,toploorder);
        
    //     int n = toploorder.size();
    //     vector<int>distance(n,INT_MAX);
    //     distance[src]=0;

    //     for(auto nbr: Maplist[src]){
    //         //nbr ->(a,b)
    //         //a = node
    //         //b = weight
    //         int  node = nbr.first;
    //         int weight = nbr.second;

    //         if(distance[src] + weight <distance[src]){
    //             distance[node]=distance[src]+weight;
    //         }
             
    //     }
    //     //main logic
    //     while(!toploorder.empty()){
    //         int frontnode = toploorder.top();
    //         toploorder.pop();

    //         for(auto nbr: Maplist[frontnode]){
    //         //nbr ->(a,b)
    //         //a = node
    //         //b = weight
    //         int  node = nbr.first;
    //         int weight = nbr.second;

    //         if(distance[frontnode] + weight < distance[node]){
    //             distance[node]=distance[frontnode]+weight;
    //         }
             
    //     }


    //     }

    //     cout<<"distance :- "<<endl;
    //     for(int i=0;i<5;i++){
    //         cout<<"Distance From 0 to "<<i<<" is :- "<<distance[i]<<endl;
    //     }
    // }
 };
 int main(){
    Graph g;
    g.add_node(0,2,13,1);
    g.add_node(0,1,5,1);
    g.add_node(0,4,3,1);
    g.add_node(1,2,7,1);
    g.add_node(1,4,1,1);
    g.add_node(4,3,6,1);
    g.add_node(3,2,2,1);


    return 0;
 }