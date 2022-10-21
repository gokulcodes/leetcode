class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> hash;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) hash[nums[i]].push_back(i);
        
        for(auto &x : hash){
            
            for(int j = 1; j < x.second.size(); j++){
                int f = x.second[j - 1], s = x.second[j];
                if(abs(f - s) <= k) return true;
            }
            
        }
        
        return false;
    }
};