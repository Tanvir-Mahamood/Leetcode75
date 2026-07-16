class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i=1; i<=n; i++) {
            int idx = i - (1 << (int)log2(i));
            ans[i] = ans[idx] + 1;
        }
        return ans;
    }
};