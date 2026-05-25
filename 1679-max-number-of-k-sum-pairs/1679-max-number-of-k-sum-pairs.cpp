class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lft = 0, rgt = nums.size() - 1, cnt = 0;
        while(lft < rgt) {
            int sum = nums[lft] + nums[rgt];
            if(sum == k) {
                cnt++;
                lft++;
                rgt--;
            }
            else if(sum < k) lft++;
            else rgt--;
        }
        return cnt;
    }
};