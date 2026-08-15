class Solution {
public:
    // Bottom Up (Tabulation) (Time: O(n), Space: O(n))
    /*
    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n < 3) return 1;

        int dp[n+1];
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
    */

    // Space Optimised Bottom Up (Time: O(n), Space: O(1))
    /*
    int tribonacci(int n) {
        int a0 = 0, a1 = 1, a2 = 1, s;
        if(n == 0) return a0;
        else if(n < 3) return a1;
        for(int i=3; i<=n; i++) {
            s = a0 + a1 + a2;
            a0 = a1;
            a1 = a2;
            a2 = s;
        }
        return s;
    }
    */

    // Top Down Approach (Time: O(n), Space: O(n)))
    int solve(vector<int> &dp, int n) {
        if(n < 3) return dp[n];
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(dp, n-1) + solve(dp, n-2) + solve(dp, n-3);
    }

    int tribonacci(int n) {
        if(n == 0) return 0;
        else if(n < 3) return 1;

        vector<int> dp(n+1, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        return solve(dp, n);
    }
};