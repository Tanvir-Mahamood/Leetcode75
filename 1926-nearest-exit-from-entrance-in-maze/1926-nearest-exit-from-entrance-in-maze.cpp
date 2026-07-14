class Solution {
private:
    bool isValid(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &maze) {
        int row = maze.size();
        int col = maze[0].size();
        if(x < 0 || x >= row || y < 0 || y >= col) return false;
        if(visited[x][y]) return false;
        if(maze[x][y] == '+') return false;
        return true;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void bfs(int srcX, int srcY, vector<vector<bool>> &visited, vector<vector<int>> &distance, vector<vector<char>> &maze) {
        queue<pair<int, int>> q;
        q.push({srcX, srcY});
        visited[srcX][srcY] = true;
        distance[srcX][srcY] = 0;

        while(!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                if(isValid(currX+dx[i], currY+dy[i], visited, maze)) {
                    int newX = currX + dx[i];
                    int newY = currY + dy[i];

                    q.push({newX, newY});
                    visited[newX][newY] = true;
                    distance[newX][newY] = distance[currX][currY] + 1;
                }
            }
        }
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int row = maze.size();
        int col = maze[0].size();
        int x = entrance[0];
        int y = entrance[1];

        vector<vector<int>> distance(row,vector<int>(col, -1));
        vector<vector<bool>> visited(row,vector<bool>(col, false));

        bfs(x, y, visited, distance, maze);

        int minDistance = INT_MAX;
        for(int i=0; i<row; i++) {
            if(distance[i][0] >= 1) minDistance = min(minDistance, distance[i][0]);
            if(distance[i][col-1] >= 1) minDistance = min(minDistance, distance[i][col-1]);
        }
        for(int j=0; j<col; j++) {
            if(distance[0][j] >= 1) minDistance = min(minDistance, distance[0][j]);
            if(distance[row-1][j] >= 1) minDistance = min(minDistance, distance[row-1][j]);
        }

        if(minDistance == INT_MAX) return -1;
        else return minDistance;
    }
};