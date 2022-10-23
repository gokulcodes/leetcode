class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2, dup = -1, sum = 0;
        
        map<int, int> hash;
        for(auto x : nums) {
            hash[x]++;
            if(hash[x] > 1) {
                dup = x;
            }
            sum += x;
        }
        
        int mis = abs(total - (sum - dup));
        
        return {dup, mis};
        
    }
};