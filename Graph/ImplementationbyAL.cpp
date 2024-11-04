#include<iostream>
#include<list>
using namespace std;
//undirected graph
class Graph{
    int V;
    //unweighted graph
    // list<int>* li;


    //weighted graph
    list<pair<int,int>>*li;

public:
    Graph(int V){
        this->V=V;
        // unweighted graph
        // li=new list<int>[V];

        //w graph
        li=new list<pair<int,int>>[V];


    }
    //uw graph

    // void addEdge(int u,int v){
    //     li[u].push_back(v);
    //     li[v].push_back(u);
    // }


    //w graph
    void addEdge(int u,int v,int w){
        li[u].push_back(make_pair(v,w));
        li[v].push_back(make_pair(u,w));
    }
    //uw graph

    //  void print(){
    //     for(int i=0;i<V;i++){
    //         list<int>neighbour=li[i];
    //         cout<<i<<" :";
    //         for(auto const& pr:neighbour){
    //             cout<<pr<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }

    //w graph
    void print(){
        for(int i=0;i<V;i++){
            list<pair<int,int>>neighbour=li[i];
            cout<<i<<" :";
            for(auto const& pr:neighbour){
                cout<<"("<<pr.first<<","<<pr.second<<")";
            }
            cout<<endl;
        }
    }

};
int main(){
    Graph gp(5);
    //uw graph
    
    // gp.addEdge(0,1);
    // gp.addEdge(1,2);
    // gp.addEdge(1,3);
    // gp.addEdge(2,3);
    // gp.addEdge(2,4);

    //w graph
    gp.addEdge(0,1,5);
    gp.addEdge(1,2,4);
    gp.addEdge(1,3,3);
    gp.addEdge(2,3,2);
    gp.addEdge(2,4,1);

    gp.print();

    return 0;
}