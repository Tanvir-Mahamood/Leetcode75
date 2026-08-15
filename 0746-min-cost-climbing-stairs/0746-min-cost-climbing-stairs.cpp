class Solution {
public:
    int solve(vector<int>& cost, int idx, vector<int> &dp) {
        if(idx <= 1) return cost[idx]; 
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = cost[idx] + min(solve(cost, idx-1, dp), solve(cost, idx-2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); // top floor cost
        int n = cost.size();
        vector<int> dp(n, -1);
        return solve(cost, n-1, dp);
    }
};