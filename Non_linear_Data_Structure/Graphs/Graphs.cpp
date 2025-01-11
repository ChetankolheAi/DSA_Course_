#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
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
    void BFS(int src){
        queue<int> q;
        unordered_map<int,bool> visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int Frontnode = q.front();
            cout<<Frontnode<<",";
            q.pop();

            for(auto neighbour : maplist[Frontnode]){

                int node= neighbour;
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;

                }
            }
        }

    }

    void DFSapply(int src , unordered_map<int,bool>& visited){
        cout<<src<<",";
        visited[src]= true;

        for(auto neighbour: maplist[src]){
            if(!visited[neighbour]){
                DFSapply(neighbour,visited);
            }
        }

    }
    void DFS(int n){
        int src = 0;
        unordered_map<int , bool>visited;
        DFSapply(src,visited);
    }
};
int main(){
     Graphs g;
    g.add(0,1,1);
    g.add(0,2,1);
    g.add(0,8,1);
    g.add(0,6,1);
    g.add(1,3,1); n b
    g.add(2,3,1);
    g.add(3,4,1);
    g.add(3,5,1);
    g.add(4,5,1);
    g.display(4);
    cout<<endl<<"BFS :-";
    g.BFS(0);
    cout<<endl<<"DFS :-";
    g.DFS(8);
    return 0;
}