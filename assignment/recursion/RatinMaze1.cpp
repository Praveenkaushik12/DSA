#include<iostream>
#include<vector>
using namespace std;

bool isSafe(const vector<vector<int>>& maze, int i, int j, int n) {
    return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1);
}

int RatinMaze(vector<vector<int>>& maze, int i, int j, int n,string ans) {
    if (i == n - 1 && j == n - 1) {
        cout<<ans<<endl;
        return 1;
    }

    // Mark the cell as visited
    maze[i][j] = -1;

    int paths = 0;

    // Move up
    if (isSafe(maze, i - 1, j, n)) {
        paths += RatinMaze(maze, i - 1, j,n,ans+'U');
    }

    // Move right
    if (isSafe(maze, i, j + 1, n)) {
        paths += RatinMaze(maze, i, j + 1, n,ans+'R');
    }

    // Move down
    if (isSafe(maze, i + 1, j, n)) {
        paths += RatinMaze(maze, i + 1, j, n,ans+'D');
    }

    // Move left
    if (isSafe(maze, i, j - 1, n)) {
        paths += RatinMaze(maze, i, j - 1, n,ans+'L');
    }

    // Unmark the cell as visited (backtrack)
    maze[i][j] = 1;

    return paths;
}
int main(){
    int n=4;
    string ans="";
    vector<vector<int>>maze={
        {1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}
    };
    cout<<RatinMaze(maze,0,0,n,ans);
    return 0;
}