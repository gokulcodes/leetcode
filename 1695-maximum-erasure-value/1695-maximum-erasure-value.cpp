class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, ans = 0, res = INT_MIN;;
        map<int, int> ind;
        
        vector<int> prefix(n);
        
        for(int i = 0; i < n; i++) {
            if(i == 0) prefix[i] = nums[i];
            else prefix[i] = nums[i] + prefix[i - 1];
        }
        
        for(i = 0; i < n; i++){
            if(ind.find(nums[i]) != ind.end()){
                ans = max(ans, i - j);
                
                // if(i - j == ans){
                    if(j - 1 >= 0)
                        res = max(res, prefix[i - 1] - prefix[j - 1]);
                    else res = max(res, prefix[i - 1]);
                // }
                
                j = max(j, ind[nums[i]] + 1);
            }
            
            ind[nums[i]] = i;
        }
        
        ans = max(ans, i - j);
        
        res = max(res, prefix[i - 1] - (j - 1 >= 0 ? prefix[j - 1] : 0));
        
        return res;
    }
};
