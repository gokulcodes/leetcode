class Solution {
public:
    
    map<int, int> dp;
    int compute(vector<int>& nums, int index){
        if(index >= nums.size())
            return 0;
        
        if(dp.find(index) != dp.end()) return dp[index];
        
        int pick = nums[index] + compute(nums, index + 2);
        int not_pick = 0 + compute(nums, index + 1);
        
        dp[index] = max(pick, not_pick);
        
        return dp[index];
    }
    
    int rob(vector<int>& nums) {
        int res = compute(nums, 0);
        
        for(auto x : dp) cout << x.second << " ";
        cout << endl;
        
        return res;
    }
};