class Solution {
public:
    int maxArea(vector<int>& height) {
        int currAmtWater, maxAmtWater = 0, lft = 0, rgt = height.size() - 1;
        while(lft < rgt) {
            currAmtWater = (rgt-lft) * min(height[lft], height[rgt]);
            maxAmtWater = max(maxAmtWater, currAmtWater);

            if(height[lft] < height[rgt]) lft++;
            else if(height[lft] > height[rgt]) rgt--;
            else lft++, rgt--;
        }
        return maxAmtWater;
    }
};