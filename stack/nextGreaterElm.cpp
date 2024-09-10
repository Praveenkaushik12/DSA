#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void nextGreaterElm(vector<int>& nums) {
    int n = nums.size();
    stack<int> s;
    vector<int> result(n, -1); // Initialize result vector with -1

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i]) {
            s.pop();
        }

        if (!s.empty()) {
            result[i] = s.top();
        }

        s.push(nums[i]);
    }

    nums = result; // Assign the result to nums
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    nextGreaterElm(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
