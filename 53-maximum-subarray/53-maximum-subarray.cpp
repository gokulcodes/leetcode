class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global = INT_MIN, local_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            local_sum += nums[i];
            global = max(local_sum, global);
            local_sum = max(0, local_sum);
        }
        return global;
    }
};