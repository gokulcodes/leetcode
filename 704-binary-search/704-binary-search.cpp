class Solution {
public:
    
    int binarySearch(int s, int e, int target, vector<int>& nums){
        if(s > e) return -1;
        int md = (s + e) / 2;
        if(nums[md] == target) return md;
        if(nums[md] > target)
            return binarySearch(s, md - 1, target, nums);
        
        return binarySearch(md + 1, e, target, nums);
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size() - 1, target, nums);
    }
};