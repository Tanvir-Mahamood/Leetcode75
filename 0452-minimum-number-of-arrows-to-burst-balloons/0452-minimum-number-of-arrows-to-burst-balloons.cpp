class Solution {
private:
    bool doOverlap(int lft, int rgt, int l, int r) {
        if(l <= rgt) return true;
        else return false;
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int lft = points[0][0];
        int rgt = points[0][1];
        int cnt = 1;

        for(int i=1; i<points.size(); i++) {
            int l = points[i][0];
            int r = points[i][1];

            if(doOverlap(lft, rgt, l, r)) {
                cnt = cnt;
                lft = max(lft, l);
                rgt = min(r, rgt);
            }
            else {
                cnt += 1;
                lft = l;
                rgt = r;
            }
        }
        return cnt;
    }
};