#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<limits.h>
#include <vector>
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

   void Shortest_Path_BFS(int src , int dist){

    queue<int>q;
    unordered_map<int,bool>visited;
    unordered_map<int,int>parent;


    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    while(!q.empty()){

        int topNode = q.front();
        q.pop();
        for( auto nbr : Maplist[topNode]){

            int node  = nbr.first;
            int nodeweight = nbr.second;

            if(!visited[node]){
                q.push(node);
                visited[node]=true;
                parent[node]= topNode;
            }
        }
    }

    vector<int> path;
    int  node = dist;
    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());
    cout<<"Shortest Path is :- ";
    for(auto i : path){
        cout<<i<<"->";
    }


   }
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

    g.Display(5);
    g.Shortest_Path_BFS(0,3);



    return 0;
 }