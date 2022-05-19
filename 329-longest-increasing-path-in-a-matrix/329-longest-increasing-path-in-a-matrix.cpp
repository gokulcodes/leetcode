class Solution {
public:
    
    int bfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>> &dp){
        
        int best = 1;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        if(dp[i][j] != -1) return dp[i][j];
        
        for(auto x : dir){
            int dx = x[0] + i, dy = x[1] + j;
            if(dx >= 0 and dx < matrix.size() and dy >= 0 and dy < matrix[0].size() and matrix[i][j] < matrix[dx][dy]){
                best = max(bfs(matrix, dx, dy, dp) + 1, best);
            }
        }
        dp[i][j] = best;
        
        return best;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size(), mx = 1;
        
        vector<vector<int>> dp(r, vector<int>(c, -1));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                // if(dp[i][j] == -1)
                    mx = max(bfs(matrix, i, j, dp), mx);
            }
        }
        
        return mx;
    }
};