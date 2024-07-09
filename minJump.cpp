#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int countJumpUsingMem(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();
        // Base case: when we reach the last index
        if (index >= n - 1) return 0;
        // If the current position is zero, we can't move further
        if (nums[index] == 0) return INT_MAX;
        // Return the cached result if already computed
        if (dp[index] != INT_MAX) return dp[index];

        int mini = INT_MAX;
        // Try all steps from 1 to nums[index]
        for (int i = 1; i <= nums[index]; i++) {
            int jumps = countJumpUsingMem(nums, index + i, dp);
            if (jumps != INT_MAX) {
                mini = min(mini, jumps + 1);
            }
        }

        dp[index] = mini;
        return dp[index];
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX); // Initialize dp array with INT_MAX
        return countJumpUsingMem(nums, 0, dp);
    }
};
