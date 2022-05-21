class Solution {
public:
    int res = INT_MAX;
    
    void recurse(vector<int>& coins, int i, int target, int cnt){
        
        // if(dp[target]) return dp[target];
        
        if(target == 0){
            res = min(res, cnt);
            return;
        }
        
        while(i < coins.size() and target - coins[i] >= 0){
            recurse(coins, i ,  target - coins[i], cnt + 1);
            i++;
            recurse(coins, i + 1, target - coins[i], cnt);
        }
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++){
            for(auto x : coins){
                if(i - x >= 0){
                    dp[i] = min(dp[i], 1 + dp[i - x]);
                }
            }
        }
            
        return dp[amount] != INT_MAX ? dp[amount] : -1;
     }
};