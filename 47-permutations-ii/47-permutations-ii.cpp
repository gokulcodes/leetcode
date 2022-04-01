class Solution {
public:
    vector<vector<int>> uniqs;
    
    void permute(int idx, vector<int>& nums, map<vector<int>, bool>& res){
        if(idx == nums.size()){
            if(res[nums]) return;
            res[nums] = true;
            uniqs.push_back(nums);
            return;
        }
       
        if(res[nums]) return;
        
        for(int i = 0; i < nums.size(); i++){
            swap(nums[i], nums[idx]);
            permute(idx + 1, nums, res);
            swap(nums[i], nums[idx]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<vector<int>, bool> hash;
        permute(0, nums, hash);
        return uniqs;
    }
    
};