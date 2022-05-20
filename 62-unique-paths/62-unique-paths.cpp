class Solution {
public:
    
//     int recurse(int i, int j, int m, int n, vector<vector<int>>& dp){
//         if(i == m - 1 and j == n - 1){
//             return 1;
//         }
        
//         if(i == m || j == m) return 0;
        
//         // if(dp[i][j]) return 1;
        
//         // dp[i][j] = 1;
        
//         // cout << i << " " << j << endl;
        
//         return recurse(i + 1, j, m, n, dp) + recurse(i, j + 1, m, n, dp);
//     }
    
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
        
        // for(auto x : dp){
        //     for(auto y : x){
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
        
        return dp[0][0];
    }
};