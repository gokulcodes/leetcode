class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            
            int last = INT_MAX;
            bool sorted = true;
            
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                
                if(last == INT_MAX) {
                    last = nums[j];
                    continue;
                }
                
                if(nums[j] - last < 0) {
                    sorted = false;
                    break;
                }
                
                last = nums[j];
            }
            
            if(sorted) return true;
            
        }
        
        
        return false;
    }
};