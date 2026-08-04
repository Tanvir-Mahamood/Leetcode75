class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> pending;
        for(int child=0; child<n; child++) {
            while(!pending.empty() && temperatures[child] > temperatures[pending.top()]) {
                int parent = pending.top();
                pending.pop();
                ans[parent] = child - parent;
            }
            pending.push(child);
        }
        return ans;
    }
};