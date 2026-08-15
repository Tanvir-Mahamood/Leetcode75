class Solution {
public:
    // Top Down Approach (Memoization) (Time: O(n), Space: O(n))
    /*
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
    */

    // Bottom Up Approach (Tabulation) (Time: O(n), Space: O(n))
    /*
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return dp.back();
    }

    // Space Optimised Bottom Up Approach (Time: O(n), Space: O(1))
    */
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        int a0 = cost[0];
        int a1 = cost[1];
        int sum = min(a0, a1);
        for(int i=2; i<n; i++) {
            sum = min(a0, a1) + cost[i];
            a0 = a1;
            a1 = sum;
        }
        return sum;
    }
};