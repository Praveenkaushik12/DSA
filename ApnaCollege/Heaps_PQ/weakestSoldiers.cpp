#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Row{
public:
    int count;
    int idx;

    Row(int count,int idx){
        this->count = count;
        this->idx = idx;
    }

    // Comparator for priority queue (min-heap by default in C++)
    bool operator < (const Row &obj) const {
        if(this->count == obj.count){
            return this->idx > obj.idx; // Lower index is prioritized
        }
        return this->count > obj.count; // Fewer soldiers are prioritized
    }

};

void weakestSoldier(vector<vector<int>> matrix, int k) {
    vector<Row> row;
    
    // Counting soldiers (1s) in each row
    for(int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for(int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) { // Increment column (j)
            count++;
        }

        row.push_back(Row(count, i)); // Store count and index of row
    }

    // Creating a priority queue with rows sorted by soldier count and index
    priority_queue<Row> pq(row.begin(), row.end());

    // Output the k weakest rows
    for(int i = 0; i < k; i++) {
        cout << "Row " << pq.top().idx << " is one of the weakest." << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    
    weakestSoldier(matrix, 2); // Finding the 2 weakest rows

    return 0;
}
