class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), total = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) total += matrix[i][0], dp[i][0] = matrix[i][0];
        for(int i = 1; i < m; i++) total += matrix[0][i], dp[0][i] = matrix[0][i];
        
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0) continue;
                dp[i][j] = matrix[i][j] + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                total += dp[i][j];
            }
        }
        
        return total;
    }
};