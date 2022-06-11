class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        auto s = accumulate(nums.begin(), nums.end(), 0);
        if(s < target) return -1;
        
        map<int, int> m;
        int n = nums.size(), curr = 0;
        
        m[0] = 0;
        
        for(int i = n - 1; i >= 0; i--){
            curr += nums[i];
            m[curr] = n - i;
        }
        
        // for(auto x : m) cout << x.first << " " << x.second << endl;
        
        curr = 0;
        int best = INT_MAX;
        if(m[target] != 0) {
            best = min(best, m[target]);
        }
        
        curr = 0;
        for(int i = 0; i < n; i++){
            curr += nums[i];
            if(m.find(target - curr) != m.end()){
                // cout << m[target - curr] << " " << i + 1 << endl;
                best = min(best, m[target-curr] + i + 1);
            }
        }
        
        if(best == INT_MAX) return -1;
        
        return best;
    }
};