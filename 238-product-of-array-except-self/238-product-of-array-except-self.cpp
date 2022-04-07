class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        
        for(int i = 0; i < n; i++){
            if(i == 0) prefix[i] = nums[i];
            else{
                prefix[i] = prefix[i-1] * nums[i];
            }
        }
        
        for(int i = n-1; i > 0; i--){
            if(i == n-1) suffix[i] = nums[i];
            else {
                suffix[i] = suffix[i+1] * nums[i];
            }
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(i == 0) res.push_back(suffix[i+1]);
            else if(i == n-1) res.push_back(prefix[n-2]);
            else res.push_back(suffix[i+1] * prefix[i-1]);
        }
        
        return res;
    }
};