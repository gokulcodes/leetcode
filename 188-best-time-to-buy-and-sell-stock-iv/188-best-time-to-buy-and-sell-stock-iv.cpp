class Solution {
public:
    
    int f(int i, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(i >= prices.size()) return 0;
        if(k == 0) return 0;
        
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        
        int profit = INT_MIN;
        if(buy){
            int pick = -prices[i] + f(i + 1, 0, k, prices, dp);
            int not_pick = 0 + f(i + 1, 1, k, prices, dp);
            profit = max(profit, max(pick, not_pick));
        }else{
            int pick = prices[i] + f(i + 1, 1, k - 1, prices, dp);
            int not_pick = f(i + 1, 0, k, prices, dp);
            profit = max(profit, max(pick, not_pick));
        }
        
        return dp[i][buy][k] = profit;
    }
        
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return f(0, 1, k, prices, dp);
    }
};