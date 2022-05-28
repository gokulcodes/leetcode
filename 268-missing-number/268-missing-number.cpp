class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long total = n * (n + 1) / 2;
        
        long long sum  = 0;
        for(auto x : nums) sum += x;
        
        cout << total << " " << sum << endl;
        
        return total - sum;
    }
};