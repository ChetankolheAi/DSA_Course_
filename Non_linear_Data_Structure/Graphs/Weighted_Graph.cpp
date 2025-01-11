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
};
int main(){
     Graphs g;
     g.add(0,1,2,1);
     g.add(0,2,2,1);
     g.add(0,8,2,1);
     g.add(0,6,2,1);
     g.add(1,3,2,1);
     g.add(2,3,2,1);
     g.add(3,4,2,1);
     g.add(3,5,2,1);
     g.add(4,5,2,1);
     g.display(4);
     
     g.BFS(0);
     g.DFS(8);
     return 0;
}