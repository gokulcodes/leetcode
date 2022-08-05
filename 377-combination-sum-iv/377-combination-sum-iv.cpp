class Solution {
public:
    map<int, int> dp;
        
    int getCount(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp.find(target) != dp.end()) return dp[target];
        
        int total = 0;
        for(auto x : nums){
            if(target >= x)
                total += getCount(nums, target - x);
        }
        
        dp[target] = total;
        
        return total;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        return getCount(nums, target);
    }
};