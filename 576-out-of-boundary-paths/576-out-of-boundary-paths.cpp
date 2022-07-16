class Solution {
public:
    int M = 1000000007;
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        
        return path(m, n, maxMove, startRow, startColumn, dp);
        
    }
    
    int path(int m, int n, int move, int i, int j, vector<vector<vector<int>>> &dp){
        if(i == m || j == n || i < 0 || j < 0) return 1;
        
        if(move == 0) return 0;
        
        if(dp[i][j][move] >= 0) return dp[i][j][move];
        
        dp[i][j][move] = ((path(m, n, move - 1, i - 1, j, dp) + path(m, n, move - 1, i + 1, j, dp)) % M + (path(m, n, move - 1, i, j - 1, dp) + path(m, n, move - 1, i, j + 1, dp)) % M) % M;
        
        return dp[i][j][move];
    }
    
};