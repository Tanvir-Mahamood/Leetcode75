class Solution {
public:
    // Bottom Up (Tabulation) (Time: O(n), Space: O(n))
    /*
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.front();

        vector<int> dp(n);
        dp[0] = nums[0], dp[1] = max(nums[1], dp[0]);
        for(int i=2; i<n; i++) {
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]); // max(pick, not pick)
        }
        return dp.back();
    }
    */

    // Space Optimized Bottom Up (Time: O(n), Space: O(1))
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums.front();

        int first = nums[0];
        int second = max(nums[0], nums[1]);
        for(int i=2; i<n; i++) {
            int ans = max(nums[i]+first, second); // max(pick, not pick)
            first = second;
            second = ans;
        }
        return second;
    }
};