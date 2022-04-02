class Solution {
public:
    vector<vector<int>> uniqs;
    
    void permute(int idx, vector<int>& nums, map<vector<int>, bool>& dp){
        if(idx == nums.size()){
            if(dp[nums]) return;
            dp[nums] = true;
            uniqs.push_back(nums);
            return;
        }

        if(dp[nums]) return;

        for(int i = 0; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            permute(idx + 1, nums, dp);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<vector<int>, bool> hash;
        permute(0, nums, hash);
        return uniqs;
    }
    
};