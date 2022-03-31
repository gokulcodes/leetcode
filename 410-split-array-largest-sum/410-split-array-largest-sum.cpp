class Solution {
public:
    bool maxSum(int limit, vector<int>& nums, int m){
        int sum = 0, subarray = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > limit){
                subarray++;
                sum = nums[i];
            }
        }
        return subarray + 1 <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0);
        
        int res = r;
        
        while(l <= r){
            int md = (l + r) / 2;
            // cout << md << endl;
            if(maxSum(md, nums, m)){
                res = md;
                r = md - 1;
            } else {
                l = md + 1;
            }
        }
        
        return res;
    }
};