class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0, res = INT_MIN;;
        map<int, int> ind;
        
        vector<int> prefix(n);
        
        for(int i = 0; i < n; i++) {
            prefix[i] = nums[i] + (i - 1 >= 0 ? prefix[i - 1] : 0);
        }
        
        for(i = 0; i < n; i++){
            if(ind.find(nums[i]) != ind.end()){
                ans = max(ans, i - j);
                
                res = max(res, prefix[i - 1] - (j - 1 >= 0 ? prefix[j - 1] : 0));
                
                j = max(j, ind[nums[i]] + 1);
            }
            
            ind[nums[i]] = i;
        }
        
        ans = max(ans, i - j);
        
        res = max(res, prefix[i - 1] - (j - 1 >= 0 ? prefix[j - 1] : 0));
        
        return res;
    }
};
