class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> dp;
        
        for(auto x : s) dp[x]++;
        for(auto x : t) dp[x]--;
        
        for(auto x : dp) if(x.second != 0) return false;
        
        return true;
    }
};