class Solution {
public:
    int helper(int n, int i, vector<int>& nums, vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        
        dp[i] = max((nums[i] + helper(n, i+2, nums, dp)), helper(n, i+1, nums, dp));

        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n, 0, nums, dp);
    }
};
