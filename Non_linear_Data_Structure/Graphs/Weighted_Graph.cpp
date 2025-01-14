#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graphs{
    public:

    //first int for key
    //second int for adjacent Node 
    //third int is the weight 
    unordered_map <int, list<pair<int,int>>> maplist;

    void add (int a , int b ,int weight, bool Directed){
        //if directed then 1 else 0
        if(Directed){
            maplist[a].push_back({b,weight});
        }
        else{
            maplist[b].push_back({a,weight});
            maplist[a].push_back({b,weight});
        }
    }

    void display(int n){
         for(int i=0;i<n;i++){
            cout<<i<<":";
            cout<<"{";
            list<pair<int,int>> temp = maplist[i];
            for(auto j: temp){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }
            cout<<"}"<<endl;
         }
    }
    void BFS(int src){
        queue<int> q;
        unordered_map<int,bool>visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int Frontnode=q.front();
            cout<<Frontnode<<",";
            q.pop();


            for(auto neighbour : maplist[Frontnode]){

                int node= neighbour.first;
                int weight = neighbour.second;
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                }
            }

        }
    }
    void dfsapply(int src , unordered_map<int,bool>& visited){
        visited[src]=true;
        cout<<src<<",";

        for(auto neighbour: maplist[src]){
            int node = neighbour.first;
            if(!visited[node]){
                dfsapply(node,visited);
            }
        }
    }

    void DFS(int n){
        int src=0; //src is starting Node
        unordered_map<int,bool>visited;
        cout<<endl<<"DFS :- ";
        dfsapply(src,visited);

    }

    void prims_algorithm(int src){
        queue<int>q;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>visited_weight;

        q.push(src);
        visited[src]=true;
        visited[src]=true;

        while(!q.empty()){

            int Frontnode = q.front();
            cout<<Frontnode<<",";
            q.pop();

            for (auto neigh : maplist[Frontnode]) {

                int node = neigh.first;  
                int weight = neigh.second;  

                if(!visited[node]){
                    q.push(node);
                    visited_weight[weight]=true;
                    visited[node]=true;
                }

        }
    }
    }
    bool Cycle_Check_directed_graph(int node ,unordered_map<int,bool>& visited , unordered_map<int,bool>& path){
        visited[node]=true;
        path[node]=true;

        for(auto neigh : maplist[node]){

            if(!visited[neigh.first]){
                bool ans = Cycle_Check_directed_graph(neigh.first , visited , path);
                if(ans){
                    return true;
                }

            }
            else if(visited[neigh.first] && path[neigh.first]){
                return true;
            }
        }
        path[node] = false;
        return false;

    }

    bool isCyclic(int n) {

        unordered_map<int, bool> visited;
        unordered_map<int,bool> path;
     

        for (int i = 0;i<n;i++){
            if (!visited[i]) {
                if (Cycle_Check_directed_graph(i, visited,path)) {
                    return true;
                }
            }
        }
        return false;
    }

};
int main(){
     Graphs g;
    g.add(0,1,2,1);
    g.add(1,2,2,1);
    g.add(2,3,2,1);
     
    bool ans =g.isCyclic(4);
     if(ans){
        cout<<"Cycle present"<<endl;

     }
     else{
        cout<<"nOt"<<endl;
     }
     return 0;
}