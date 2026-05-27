class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int idx = -1, n = nums.size();
        vector<int> left(n), right(n);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        
        for(int i=1,j=n-2; i<n&&j>=0; i++,j--) {
            left[i] = left[i-1] + nums[i];
            right[j] = right[j+1] + nums[j];
        }

        for(int i=0; i<n; i++) {
            if(left[i] == right[i]) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};