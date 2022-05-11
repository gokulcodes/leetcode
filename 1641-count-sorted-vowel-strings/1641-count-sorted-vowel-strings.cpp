class Solution {
public:
    
    int countVowelStrings(int n) {
        if(n == 1) return 5;
        
        vector<int> dp = {15,10,6,3,1};
        
        n -= 2;
        
        while(n--){
            for(int i = 0; i < 5; i++){
                for(int j = i + 1; j < 5; j++){
                    dp[i] += dp[j];
                }
            }
            // for(auto x : dp) cout << x << ' ';
            // cout << endl;
        }
        return dp[0];
    }
};