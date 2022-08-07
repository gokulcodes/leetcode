class Solution {
public:
    int MOD = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<long long> prev = {1,1,1,1,1};
        
        for(int i = 2; i <= n; i++){
            vector<long long> dp = prev;
            
            dp[0] = (prev[1] + prev[2] + prev[4]) % MOD;
            dp[1] = (prev[0] + prev[2]) % MOD;
            dp[2] = (prev[1] + prev[3]) % MOD;
            dp[3] = (prev[2]) % MOD;
            dp[4] = (prev[2] + prev[3]) % MOD;
            
            prev = dp;
            
        }
        
        int total = 0;
        for(auto x : prev) total = (total + x) % MOD;
        
        return total;
    }
};