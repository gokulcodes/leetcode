class Solution {
public:
    
    bool isposs = false;
    
    map<int, bool> dp;
    
    void allPossible(int i, vector<int>& nums){
        
        if(i >= nums.size() - 1 || i + nums[i] >= nums.size() - 1) {
            isposs = true;
            return;
        }
        
        if(dp[i]) return;
        
        if(nums[i] == 0) return;
        
        dp[i] = true;
        
        for(int j = i + 1; j <= min((int)nums.size() - 1, i + nums[i]); j++)
            allPossible(j, nums);

    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        int n = nums.size();
        
        int goal = n - 1, ptr = n - 2, flag = true;
        
        while(ptr >= 0){
            // cout << nums[ptr] << " " << ptr << " " << goal << endl;
            
            if(nums[ptr] + ptr >= goal){
                flag = true;
                goal = ptr, ptr--;
            }else{
                flag = false;
                ptr--;
            }
            
        }
        
        return flag;
    }
    
};