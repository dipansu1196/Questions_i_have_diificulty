class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                                  {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Check if start or end is blocked
        if (m == 0 || n == 0 || grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }
        
        // Special case: single cell
        if (m == 1 && n == 1) {
            return 1;
        }
        
        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        // Fixed: Use 'que' consistently (was mixing 'que' and 'pq')
        priority_queue<p, vector<p>, greater<p>> que;
        
        // Start with distance 1 (path length includes start cell)
        que.push({1, {0, 0}});
        result[0][0] = 1;
        
        while (!que.empty()) {
            int d = que.top().first;
            pair<int, int> node = que.top().second;
            que.pop();
            
            int x = node.first;
            int y = node.second;
            
            // If we reached the destination
            if (x == m - 1 && y == n - 1) {
                return d;
            }
            
            // Skip if we've already found a better path to this cell
            if (d > result[x][y]) {
                continue;
            }
            
            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1;
                
                // Fixed: 'result' was misspelled as 'resul'
                if (isSafe(x_, y_) && grid[x_][y_] == 0 && d + dist < result[x_][y_]) {
                    que.push({d + dist, {x_, y_}});
                    result[x_][y_] = d + dist;
                }
            }
        }
        
        return result[m-1][n-1] == INT_MAX ? -1 : result[m-1][n-1];
    }
};