class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lft = 0, rgt = 1;
        while(rgt < nums.size()) {
            if(nums[lft] == 0 && nums[rgt] != 0) {
                swap(nums[lft], nums[rgt]);
                lft++;
            }
            else if(nums[lft] != 0) {
                lft++;
            }
            rgt++;
        }
    }
};