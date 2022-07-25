class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return {-1, -1};
        
        int l = 0, r = nums.size() - 1, first = -1, last = -1;
        
        while(l <= r){
            int md = (l + r) / 2;
            
            if(nums[md] == target){
                first = md;
                r = md - 1;
            }else if(nums[md] > target) r = md - 1;
            else l = md + 1;
            
        }
        
        if(first == -1) return {-1, -1};
        
        l = first, r = nums.size() - 1;
        
        while(l <= r){
            int md = (l + r) / 2;
            
            if(nums[md] == target){
                last = md;
                l = md + 1;
            }else if(nums[md] > target) r = md - 1;
            else l = md + 1;
            
        }
        
        return {first, last};
    }
};