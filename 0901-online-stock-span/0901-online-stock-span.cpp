class StockSpanner {
private:
    vector<int> mem;
    vector<int> result;
    stack<int> st;
    int idx;
public:
    StockSpanner() {
        mem.clear();
        result.clear();
        stack<int>().swap(st);
        idx = 0;
    }
    
    int next(int price) {
        int ans = 1;
        if(st.empty()) {
            st.push(idx++);
            mem.push_back(price);
            result.push_back(ans);
            return ans;
        }
        else if(price >= mem[st.top()]) {
            while(!st.empty() && price >= mem[st.top()]) {
                ans = ans + result[st.top()];
                st.pop();
            }
            st.push(idx++);
            mem.push_back(price);
            result.push_back(ans);
            return ans;
        }
        else if(price < mem[st.top()]) {
            st.push(idx++);
            mem.push_back(price);
            result.push_back(ans);
            return ans;
        }
        return -1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */