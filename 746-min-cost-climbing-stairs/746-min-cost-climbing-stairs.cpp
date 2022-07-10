class Solution {
public:
    
    vector<int> dp;
    
    int recur(vector<int>& cost, int i){
        if(i >= cost.size() - 1){
            return 0;
        }
        
        if(dp[i] != INT_MAX) return dp[i];
        
        int first = cost[i] + recur(cost, i + 1);
        int second = cost[i + 1] + recur(cost, i + 2);
        
        dp[i] = min(first, second);
        
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(), INT_MAX);
        return recur(cost, 0);
    }
};