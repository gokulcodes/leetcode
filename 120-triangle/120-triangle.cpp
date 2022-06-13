class Solution {
public:
    
    int recur(int r, int c, vector<vector<int>>& tr, int sum, vector<vector<int>>& dp){
        if(r >= tr.size()) return 0;
        
        if(dp[r][c] != INT_MAX) return dp[r][c];
        
        dp[r][c] = tr[r][c] + min(recur(r + 1, c, tr, sum, dp), recur(r + 1, c + 1, tr, sum, dp));
        
        return dp[r][c];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        return recur(0, 0, triangle, 0, dp);
    }
};