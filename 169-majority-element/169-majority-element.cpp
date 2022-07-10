class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mj = nums[0], cnt = 1, n = nums.size();
        
        for(int i = 1; i < n; i++){
            if(nums[i] == mj){
                cnt++;
            }else if(cnt > 0){
                cnt--;
            }else{
                mj = nums[i];
                cnt++;
            }
        }
        
        return mj;
    }
};