class Solution {
public:
    vector<int> dp;
    
    void allpossible(int i, vector<int>& nums){
        
        if(i + nums[i] >= nums.size() - 1){
            dp[nums.size() - 1] = dp[i] + 1;
            return;
        }
        
        for(int j = min((int)nums.size() - 1, i + nums[i]); j >= i + 1; j--){
            
            if(dp[j] == 0) dp[j] = dp[i] + 1;
            else if(dp[j]) dp[j] = min(dp[j], dp[i] + 1);
            
            allpossible(j, nums);
            
        }
        
    }
    
    int jump(vector<int>& nums) {
        int min_steps = 0, ptr = nums.size() - 1;
        
        while(ptr > 0){
            int curr = ptr;
            for(int i = ptr; i >= 0; i--){
                if(nums[i] + i >= ptr){
                    curr = i;
                }
            }
            ptr = curr;
            min_steps++;
            // cout << ptr << endl; 
        }
        
        
        return min_steps;
    }
};