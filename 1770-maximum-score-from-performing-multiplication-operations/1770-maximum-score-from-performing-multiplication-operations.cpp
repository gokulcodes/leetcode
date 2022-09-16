class Solution {
public:
    
    int f(int i, int start, vector<int>& nm, vector<int>& mm, vector<vector<int>>& dp){
        if(i >= mm.size()) return 0;
        
        if(dp[i][start] != -1) return dp[i][start];
        
        int first = (mm[i] * nm[start]) + f(i + 1, start + 1, nm, mm, dp);
        int last = (mm[i] * nm[(nm.size() - 1) - i]) + f(i + 1, start, nm, mm, dp);
        
        return dp[i][start] = max(first, last); 
    }
    
    int maximumScore(vector<int>& nm, vector<int>& mm) {
        int n = nm.size(), m = mm.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        for(int i = m - 1; i >= 0; i--){
            for(int start = i; start >= 0; start--){
                
                int first = (mm[i] * nm[start]) + prev[start + 1], last = 0;
                int r = ((n - 1) - (i - start));
                
                if(r < n and r >= 0)
                    last = (mm[i] * nm[r]) + prev[start];

                curr[start] = max(first, last); 
                
            }
            prev = curr;
        }
        
        return prev[0];
    }
};

// nums[(n - 1) - (op - left)]