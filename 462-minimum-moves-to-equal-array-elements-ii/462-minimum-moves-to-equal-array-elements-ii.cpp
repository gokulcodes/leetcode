class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        long long res = 0, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(auto x : nums) res += max(nums[n / 2], x) - min(nums[n / 2], x);
        
        return res;
        
    }
};



// 1 + 10 + 2 + 9 = 22 / 4 = 5
// 4 + 5 + 3 + 4 = 16
    
// 1 + 2 + 3 = 6 / 3 = 2
// 1 + 0 + 1 = 2