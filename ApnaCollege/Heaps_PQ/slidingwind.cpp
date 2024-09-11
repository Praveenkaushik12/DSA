#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> result;

        // Step 1: Add first k elements to the priority queue
        for (int i = 0; i < k; i++) {
            pq.push(make_pair(nums[i], i));
        }
        result.push_back(pq.top().first);

        // Step 2: Slide the window across the array
        for (int i = k; i < nums.size(); i++) {
            while (!pq.empty() && pq.top().second <= (i - k)) {
                pq.pop();
            }
            pq.push(make_pair(nums[i], i));
            result.push_back(pq.top().first);
        }

        // Step 3: Return the result
        return result;
    }
};

// Helper function to print the result
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = solution.maxSlidingWindow(nums, k);
    printVector(result);  // Expected output: 3 3 5 5 6 7

    return 0;
}
