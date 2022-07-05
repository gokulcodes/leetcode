class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        
        int res = 0, local = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++){
            
            if(nums[i] + 1 == nums[i + 1]) local++;
            else if(nums[i] != nums[i + 1]){
                res = max(local, res);
                local = 0;
            }
            
        }
        
        res = max(local, res);
        
        return res + 1;
    }
};