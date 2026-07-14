class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            visited[idx] = true;
            vector<int> keys = rooms[idx];
            for(int key: keys) {
                if(!visited[key]) q.push(key);
            }
        }
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                return false;
            }
        }
        return true;
    }
};