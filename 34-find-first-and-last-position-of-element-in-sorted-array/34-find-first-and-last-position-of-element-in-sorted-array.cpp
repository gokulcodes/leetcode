class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return {-1, -1};
        
        int l = 0, r = nums.size() - 1, first = -1, last = -1, l1 = 0, r1 = nums.size() - 1;
        
        while(l <= r || l1 <= r1){
            int md1 = (l + r) / 2, md2 = (l1 + r1) / 2;
            
            if(l <= r){
                if(nums[md1] == target){
                    first = md1;
                    r = md1 - 1;
                }else if(nums[md1] > target) r = md1 - 1;
                else l = md1 + 1;    
                
            }else{
                if(nums[md2] == target){
                    last = md2;
                    l1 = md2 + 1;
                }else if(nums[md2] > target) r1 = md2 - 1;
                else l1 = md2 + 1;    
            }
            
            
        }
        
        return {first, last};
    }
};