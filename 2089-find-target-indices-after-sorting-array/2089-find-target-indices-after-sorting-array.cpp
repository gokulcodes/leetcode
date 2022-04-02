class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        
        // cout << r - l << endl;    
    
        vector<int> res;
        int i = l - nums.begin(), j = r - nums.begin();
        
        for(int k = i; k < j; k++) res.push_back(k);
        
        return res;
        
    }
};