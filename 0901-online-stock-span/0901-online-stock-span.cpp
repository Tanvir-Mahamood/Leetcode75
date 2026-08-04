class StockSpanner {
private:
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        stack<pair<int,int>> empty;
        st.swap(empty);
    }
    
    int next(int price) {
        int ans = 1;
        if(st.empty()) {
            st.push({price, ans});
            return ans;
        }
        else if(price >= st.top().first) {
            while(!st.empty() && price >= st.top().first) {
                ans = ans + st.top().second;
                st.pop();
            }
            st.push({price, ans});
            return ans;
        }
        else if(price < st.top().first) {
            st.push({price, ans});
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