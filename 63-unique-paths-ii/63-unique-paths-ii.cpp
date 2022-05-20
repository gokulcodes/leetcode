class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == n - 1 and j == m - 1) dp[i][j] = 1;
                else{
                    long long right = j + 1 < m ? dp[i][j + 1] : 0;
                    long long down = i + 1 < n ? dp[i + 1][j] : 0;
                    dp[i][j] = right + down;
                }
                
            }
        }
        
        // for(auto x : dp){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        
        return dp[0][0];
    }
};
