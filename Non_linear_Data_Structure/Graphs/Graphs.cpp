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

    bool Cycle_Check(int src ,unordered_map<int,bool>& visited){
        queue<int> q;
        // unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        q.push(src);
        visited[src]=true;
        parent[src] = -1;

        while(!q.empty()){
            
            int Frontnode = q.front();
         
            q.pop();

            for(auto neighbour : maplist[Frontnode]){

                int node= neighbour;
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                    parent[node] = Frontnode;

                }
                else if(visited[node] && node != parent[Frontnode]){
                    return true;
                }
            }
        }
        return false;

    }
     bool isCyclic() {
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        for (auto node : maplist) {
            if (!visited[node.first]) {
                if (Cycle_Check(node.first, visited)) {
                    return true;
                }
            }
        }
        return false;
    }


    
};
int main(){

    Graphs g;
    g.add(0,1,1);
    g.add(1,2,1);
    g.add(2,0,1);
    g.display(3);
    cout<<endl<<"BFS :-";
    g.BFS(0);
    cout<<endl<<"DFS :-";
    g.DFS(8);

    int n=3;
    if (g.isCyclic()) {
        cout <<endl<< "Cycle Present" << endl;
    } else {
        cout <<endl<< "Cycle Not Present" << endl;
    }

    return 0;
}