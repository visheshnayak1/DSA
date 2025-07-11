class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum % 2 != 0) return false;
        return subSetSum(nums, sum / 2);
    }

    bool subSetSum(vector<int>& nums, int k) {
        int n = nums.size();
        bool t[n + 1][k + 1];

        // Base cases
        for (int i = 0; i <= n; i++) t[i][0] = true;      // Subset sum = 0 is always true
        for (int j = 1; j <= k; j++) t[0][j] = false;     // Empty set can't sum to j > 0

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][k];
    }
};