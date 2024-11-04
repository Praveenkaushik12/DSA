#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
    int V;
    list<int>* li;
    bool isUndir;
public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        li = new list<int>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v) {
        li[u].push_back(v);
        if (isUndir)
            li[v].push_back(u);
    }

    void print() {
        for (int i = 0; i < V; i++) {
            cout << i + 1 << " :";  // Adjusted to print 1-based indexing
            for (int neighbor : li[i]) {
                cout << neighbor + 1 << " ";  // Adjusted to print 1-based indexing
            }
            cout << endl;
        }
    }

    bool dirCycleHelper(int src, vector<bool>& vis, vector<bool>& recPath) {
        vis[src] = true;
        recPath[src] = true;

        for (int v : li[src]) {
            if (!vis[v]) {
                if (dirCycleHelper(v, vis, recPath)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }
        recPath[src] = false;  // Remove from recursion stack before backtracking
        return false;
    }

    bool isCycleDir() {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false); //recursion path

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dirCycleHelper(i, vis, recPath)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph gp(4, false);  // Directed graph with 4 vertices
    gp.addEdge(0, 1);    // 1 -> 2
    gp.addEdge(1, 2);    // 2 -> 3
    gp.addEdge(2, 3);    // 3 -> 4

    cout << (gp.isCycleDir() ? "Cycle detected" : "No cycle detected") << endl;

    gp.print();

    return 0;
}
