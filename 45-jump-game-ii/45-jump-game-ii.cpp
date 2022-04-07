class Solution {
public:
    
    int jump(vector<int>& nums) {
        int min_steps = 0, ptr = nums.size() - 1;
        
        while(ptr > 0){
            int curr = ptr;
            
            for(int i = ptr; i >= 0; i--)
                if(nums[i] + i >= ptr) curr = i;
            
            ptr = curr;
            min_steps++;
        }
        
        return min_steps;
    }
};