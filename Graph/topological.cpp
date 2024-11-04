#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int>*li;
    bool isUndir;
public:
    Graph(int V,bool isUndir=true){
        this->V=V;
        li=new list<int>[V];
        this->isUndir=isUndir;
    }

    void addEdge(int u,int v){
        li[u].push_back(v);
        if(isUndir)
            li[v].push_back(u);
    }

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

    void toSortHelper(int src,vector<bool>&vis,stack<int>&s){ //dfs- O(V+E)
        vis[src]=true;

        list<int>neighbors=li[src];
        for(int num:neighbors){
            if(!vis[num]){
                toSortHelper(num,vis,s);
            }
        }

        s.push(src);

    }

    void toSort(){
        vector<bool>vis(V,false);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toSortHelper(i,vis,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }


};
int main(){
    Graph gp(6,false);

    gp.addEdge(2,3);
    gp.addEdge(3,1);
    gp.addEdge(4,0);
    gp.addEdge(4,1);
    gp.addEdge(5,0);
    gp.addEdge(5,2);

    gp.toSort();

    return 0;
}