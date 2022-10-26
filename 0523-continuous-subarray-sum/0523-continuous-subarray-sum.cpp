class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> hash{{0,0}};
        
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            
            if(!hash.count(sum % k))
                hash[sum % k] = i + 1;
            
            else if(hash[sum % k] < i)
                return true;
            
        }
        
        return false;
    }
};