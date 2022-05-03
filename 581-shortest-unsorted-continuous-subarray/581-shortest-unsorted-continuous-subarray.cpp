class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            if(nums[l] != temp[l] and nums[r] != temp[r]){
                break;
            }else if(nums[l] == temp[l]) l++;
            else r--;
        }
        
        return r - l + 1;
        
    }
};