#include <iostream>
#include <vector>
using namespace std;

int targetSum(vector<int> nums, int m) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: There's always 1 way to get a sum of 0 (by choosing no elements).
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (nums[i - 1] == 0) {
                // Double the count if we encounter a zero, as each subset count can either include or exclude this zero
                dp[i][j] = 2 * dp[i - 1][j];
            } else if (nums[i - 1] <= j) {
                // Include or exclude the non-zero element
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            } else {
                // Only exclude if the element is greater than the current target sum
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int main() {
    vector<int> nums = {0, 0, 1};
    int target = 1;
    cout << targetSum(nums, target);
    return 0;
}
