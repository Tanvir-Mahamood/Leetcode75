class Solution {
private:
    bool doOverlap(int rgt, int l) {
        return (l <= rgt);
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

            if(doOverlap(rgt, l)) {
                rgt = min(r, rgt);
            }
            else {
                cnt += 1;
                rgt = r;
            }
            lft = l;
        }
        return cnt;
    }
};