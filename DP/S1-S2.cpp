#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countPartitionsWithGivenDifference(const vector<int>& nums, int diff) {
    int total_sum = 0;
    for (int num : nums) total_sum += num;

    // If (total_sum + diff) is odd, we can't find integer subset sums
    if ((total_sum + diff) % 2 != 0) return 0;

    int target_sum = (total_sum + diff) / 2;
    int n = nums.size();

    // Initialize DP table with 0
    vector<vector<int>> dp(n + 1, vector<int>(target_sum + 1, 0));

    // Base case: There's one way to achieve a sum of 0: using an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target_sum; j++) {
            // Exclude the current element
            dp[i][j] = dp[i - 1][j];

            // Include the current element if it's not greater than the current sum `j`
            if (nums[i - 1] <= j) {
                dp[i][j] = (dp[i-1][j] + dp[i - 1][j - nums[i - 1]]) % MOD;
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=target_sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;

    }

    return dp[n][target_sum];
}

int main() {
    vector<int> nums = {5,2,6,4};
    int diff = 3;
    cout << "Number of partitions with given difference: " << countPartitionsWithGivenDifference(nums, diff);
    return 0;
}
