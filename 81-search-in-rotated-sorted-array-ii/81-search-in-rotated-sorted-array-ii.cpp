class Solution {
public:
    int i = -1;
    void pivot(int s, int e, vector<int>& nums){
        if(s > e) return;
        int md = (s + e) / 2;
        
        if(md > 0 && nums[md] >= nums[md - 1])
            pivot(s, md - 1, nums);
        else if(md > 0 && nums[md] < nums[md - 1]){
            i = md;
        }
        if(md + 1 < nums.size() && nums[md] <= nums[md + 1])
            pivot(md + 1, e, nums);
        else if(md + 1 < nums.size() && nums[md] > nums[md + 1]){
            i = md;
        }
    }
    
    bool binarySearch(int s, int e, vector<int>& nums, int target){
        if(s > e) return false;
        int md = (s + e) / 2;
        if(nums[md] == target) return true;
        if(nums[md] > target)
            return binarySearch(s, md - 1, nums, target);
        return binarySearch(md + 1, e, nums, target);
    }
    
    bool search(vector<int>& nums, int target) {
        pivot(0, nums.size() - 1, nums);
        
        if(nums.size() > 1){
            if(nums[0] > nums[1]) i = 1;
            if(nums[nums.size() - 1] < nums[nums.size() - 2]) i = nums.size() - 1;
        }
        
        if(i == -1) return binarySearch(0, nums.size() - 1, nums, target);
        return binarySearch(0, i, nums, target) || binarySearch(i, nums.size() - 1, nums, target);
    }
};