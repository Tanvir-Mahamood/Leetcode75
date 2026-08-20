class Solution {
public:
    // Bottom Up (Time: O(mn), Space: O(mn))
    /*
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int j=0; j<n; j++) dp[0][j] = 1;
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; // either from top or left
            }
        }
        return dp[m-1][n-1];
    }
    */

    // Bottom Up (Space Optimized) (Time: O(mn), Space: O(n))
    /*
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2,vector<int>(n, 1));
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(i&1) dp[1][j] = dp[0][j] + dp[1][j-1];
                else dp[0][j] = dp[1][j] + dp[0][j-1];
            }
        }
        return dp[(m&1)^1][n-1];
    }
    */

    // Bottom Up (Space Optimized II) (Time: O(mn), Space: O(n))
    /*
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i=1; i<m; i++) {
            partial_sum(dp.begin(), dp.end(), dp.begin());
        }
        return dp.back();
    }
    */

    // Bottom Up (Space Optimized III) (Time: O(min(m,n)), Space: O(1))
    int nCr(int N, int k) {
        long long ans = 1;
        for(int i=1; i<=k; i++) {
            ans = ans *  (N-k+i) / i;
        }
        return ans;
    }

    int uniquePaths(int m, int n) { 
        int k = min(m - 1, n - 1);
        int total = m + n - 2;


        return nCr(total, k);
    }
};