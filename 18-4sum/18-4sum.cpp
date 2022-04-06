class Solution {
public:
    long long value(int num){
        long long i = 1;
        return num * i;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> s;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int k = j + 1, l = n - 1;
                while(k < l){
                    long long temp = 
                        value(nums[i]) + value(nums[j]) + value(nums[k]) + value(nums[l]);
                    if(temp == target){
                        if(s.count({nums[i], nums[j], nums[k], nums[l]}) == 0){
                            res.push_back({nums[i], nums[j], nums[k], nums[l]});
                            s.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                        k++;
                    }else if(temp > target) l--;
                    else k++;
                    // cout << k << " " << l << " " << temp << endl;
                }
            }
        }
    
        return res;
    }
};