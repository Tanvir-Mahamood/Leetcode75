class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int lft = intervals[0][0], rgt = intervals[0][1];
        int cnt = 0;
        for(int i=1; i<intervals.size(); i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            if(r < rgt) { // kill parent interval
                cnt += 1;
            }
            else if(l < rgt) { // keep parent interval ans suicide 
                cnt += 1;
                continue;
            }
            lft = l; // defining new parent
            rgt = r;
        }
        return cnt;
    }
};