class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        else if(n == 1) return {0, 1};

        vector<int> ans(n+1);
        ans[0] = 0;
        ans[1] = 1;

        for(int i=2; i<=n; i++) {
            int idx = i - (1 << (int)log2(i));
            ans[i] = ans[idx] + 1;
        }
        return ans;
    }
};