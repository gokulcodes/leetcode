class Solution {
public:
    
    bool isValid(int a, int b, int c){
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
    
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), per = 0;
        
        for(int i = 0; i < n - 2; i++){
            if(isValid(nums[i], nums[i + 1], nums[i + 2])){
                per = max(per, nums[i] + nums[i + 1] + nums[i + 2]);
            }
        }
        
        
        return per;
    }
};
