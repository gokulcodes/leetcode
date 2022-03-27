class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        
        int i = 1;
        
        while(2 * i + 1 <= n){
            dp[2 * i] = dp[i];
            dp[2 * i + 1] = dp[i] + dp[i + 1];
            i++;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};