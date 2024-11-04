#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
//undirected graph
class Graph{
    int V;
    //unweighted graph
    list<int>* li;



public:
    Graph(int V){
        this->V=V;
        // unweighted graph
        li=new list<int>[V];



    }
    //uw graph

    void addEdge(int u,int v){
        li[u].push_back(v);
        li[v].push_back(u);
    }


    //uw graph

    void print(){
        for(int i=0;i<V;i++){
            list<int>neighbour=li[i];
            cout<<i<<" :";
            for(auto const& pr:neighbour){
                cout<<pr<<" ";
            }
            cout<<endl;
        }
    }

    bool cycleUndirectedHelper(int src,int parent,vector<bool>&vis){
        vis[src]=true;
        list<int> neighbour = li[src];
        for(int num:neighbour){
            if(!vis[num]){
                if(cycleUndirectedHelper(num,src,vis)){
                    return true;
                };
            }else{
                if(num!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool cycleUndirected() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (cycleUndirectedHelper(i, -1, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

};
int main(){
    Graph gp(7);
    //uw graph
    
    gp.addEdge(0,1);
    // gp.addEdge(0,2);
    gp.addEdge(0,3);
    gp.addEdge(1,2);
    gp.addEdge(3,4);

    cout<<gp.cycleUndirected()<<endl;

    return 0;
}