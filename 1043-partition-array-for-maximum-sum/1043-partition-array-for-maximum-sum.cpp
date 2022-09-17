class Solution {
public:
    
    int f(int i, int k, int n, vector<int>& arr, vector<int>& dp){
        if(i >= n) return 0;
        if(i == n - 1) return arr[i];
        
        if(dp[i] != -1) return dp[i];
        
        int mx = INT_MIN, mxSum = INT_MIN;
        for(int j = i; j < min(n, i + k); j++){
            mx = max(mx, arr[j]);
            int front = mx * (j - i + 1);
            mxSum = max(mxSum, front + f(j + 1, k, n, arr, dp));
        }
        
        return dp[i] = mxSum;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, k, n, arr, dp);
    }
};