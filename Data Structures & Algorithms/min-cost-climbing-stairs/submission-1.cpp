class Solution {
public:
    int helper(int n, int i, vector<int>& cost, vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        dp[i] = cost[i] + min(helper(n, i+1, cost, dp), helper(n, i+2, cost, dp));

        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(helper(n, 0, cost, dp), helper(n, 1, cost, dp));
    }
};
