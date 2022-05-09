class Solution {
public:
    
    map<int, string> mp;
    
    void permute(string s, string t, set<string>& comb, int n, string digit){
        if(t.size() == n){
            bool ok = true;
            for(int i = 0; i < n; i++){
                if(mp[digit[i] - '0'].find(t[i]) == string::npos) {
                    ok = false;
                    break;
                }
            }
            
            if(ok){
                comb.insert(t);
            }
            
            return;
        }
        
        for(int i = 0; i < s.length(); i++){
            t.push_back(s[i]);
            permute(s, t, comb, n, digit);
            t.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        mp[2] = "abc", mp[3] = "def", mp[4] = "ghi", mp[5] = "jkl", mp[6] = "mno", mp[7] = "pqrs", mp[8] = "tuv", mp[9] = "wxyz";
        
        set<string> comb;
        vector<string> res;
        
        if(digits.length() == 0) return res;
        
        string list = "", temp = "";
        for(auto x : digits){
            list += mp[x - '0'];
        }
        
        int n = digits.length();
        
        permute(list, temp, comb, n, digits);
        for(auto x : comb) res.push_back(x);
        
        return res;
            
    }
};