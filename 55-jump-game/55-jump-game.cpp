class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        int n = nums.size();
        
        int goal = n - 1, ptr = n - 2;
        
        while(ptr >= 0){
            
            if(nums[ptr] + ptr >= goal){
                goal = ptr, ptr--;
            }else{
                ptr--;
            }
            
        }
        
        return goal == 0;
    }
    
};