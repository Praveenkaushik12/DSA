#include <iostream>
#include <vector>
using namespace std;

int targetSum(vector<int> nums, int m) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the base case: there's one way to get a sum of 0, by taking no elements.
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (nums[i - 1] <= j) {
                // Include the current number in the subset or exclude it
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            } else {
                // Exclude the current number from the subset
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}

int main() {
    vector<int> nums = {1, 1, 1};
    int target = 3;
    cout << targetSum(nums, target);
    return 0;
}
