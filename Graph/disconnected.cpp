#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph {
    int V;
    list<int>* li;

public:
    Graph(int V) {
        this->V = V;
        li = new list<int>[V];
    }

    void addEdge(int u, int v) {
        li[u].push_back(v);
        li[v].push_back(u);
    }

    void print() {
        for (int i = 0; i < V; i++) {
            list<int> neighbour = li[i];
            cout << i << " : ";
            for (auto const& pr : neighbour) {
                cout << pr << " ";
            }
            cout << endl;
        }
    }

    void bfshelper(int i, vector<bool>& isVisited) {
        queue<int> q;
        q.push(i);
        isVisited[i] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbour = li[u];

            for (int num : neighbour) {
                if (!isVisited[num]) {
                    isVisited[num] = true;
                    q.push(num);
                }
            }
        }
        cout << endl;
    }

    void bfs() {
        vector<bool> isVisited(V, false);
        for (int i = 0; i < V; i++) {
            if (!isVisited[i]) {
                bfshelper(i, isVisited);
            }
        }
    }

    void dfsHelper(int u, vector<bool>& isVisited) {
        isVisited[u] = true;
        cout << u << " ";
        list<int> neighbour = li[u];
        for (int num : neighbour) {
            if (!isVisited[num]) {
                dfsHelper(num, isVisited);
            }
        }
    }

    void dfs() {
        
        vector<bool> isVisited(V, false);
        for (int i = 0; i < V; i++) {
            if (!isVisited[i]) {
                dfsHelper(i, isVisited);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph gp(10);  

  
    gp.addEdge(1, 6);
    gp.addEdge(6, 4);
    gp.addEdge(4, 9);
    gp.addEdge(4, 3);
    gp.addEdge(3, 8);
    gp.addEdge(3, 7);

    gp.addEdge(2, 5);
    gp.addEdge(0, 2);

 
    cout << "BFS Traversal:" << endl;
    gp.bfs();

    cout << "DFS Traversal:" << endl;
    gp.dfs();

    return 0;
}
