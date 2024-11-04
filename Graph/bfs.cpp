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

    void bfs(){ //O(Vertices+Edge) 
        queue<int>q;
        vector<bool>isVisted(V,false);
        q.push(0);
        isVisted[0]=true;

        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            list<int>neighbour=li[u];

            for(int num:neighbour){
                if(isVisted[num]==false){
                    isVisted[num]=true;
                    q.push(num);
                }
            }
        }
        cout<<endl;

    }



};
int main(){
    Graph gp(5);
    //uw graph
    
    gp.addEdge(0,1);
    gp.addEdge(1,2);
    gp.addEdge(1,3);
    gp.addEdge(2,3);
    gp.addEdge(2,4);

    gp.bfs();
    cout<<"---------------"<<endl;


    // gp.print();

    return 0;
}