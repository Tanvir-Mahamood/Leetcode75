class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lft = 0, slideLen = 0, maxLen = 0, zeroCnt = 0;
        for(int rgt=0; rgt<nums.size(); rgt++) {
            if(nums[rgt] == 0) {
                zeroCnt++;
            }
            if(zeroCnt > k) {
                if(nums[lft] == 0) zeroCnt--;
                lft++;
            }
            slideLen = rgt - lft + 1;
            maxLen = max(maxLen, slideLen);
        }
        return maxLen;
    }
};