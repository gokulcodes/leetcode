#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(is_sorted(nums.rbegin(), nums.rend())){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int i = 0;
        for(i = n - 1; i > 0; i--){
            if(nums[i - 1] < nums[i]) {
                i = i - 1;
                break;
            }
        }
        
        int l = i + 1, r = n - 1, j = i;
        while(l <= r){
            int md = (l + r) / 2;
            
            if(nums[md] > nums[i]){
                j = md;
                l = md + 1;
            }else r = md - 1;
        }
        
        cout << j << endl;
        
        swap(nums[j], nums[i]);
        
        for(auto x : nums) cout << x << " ";
        
        sort(nums.begin() + i + 1, nums.end());
        
    }
};