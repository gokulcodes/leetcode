class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                int total_sum = (i == n - 1);
                
                if(i != n - 1)
                    for(int k = j; k < m; k++){
                        total_sum += dp[k][i + 1];
                    }
                dp[j][i] = total_sum;
                
            }
        }
        
        return dp[0][0];
    }
};