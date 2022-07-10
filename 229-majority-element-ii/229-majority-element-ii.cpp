class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mr = n / 3;
        
        map<int, int> mp;
        vector<int> res;
        for(auto x : nums){
            mp[x]++;
        }
        
        for(auto x : mp){
            if(x.second > mr) 
                res.push_back(x.first);
        }
        
        
        return res;
    }
};