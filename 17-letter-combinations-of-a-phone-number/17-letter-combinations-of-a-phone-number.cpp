class Solution {
public:
    
    map<int, string> mp;
    
    void permute(int i, string d, string t, vector<string> &res){
        if(i >= d.length()){
            res.push_back(t);
            return;
        }
        
        for(auto x : mp[d[i] - '0']){
            t += string(1, x);
            permute(i + 1, d, t, res);
            t.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        mp[2] = "abc", mp[3] = "def", mp[4] = "ghi", mp[5] = "jkl", mp[6] = "mno", mp[7] = "pqrs", mp[8] = "tuv", mp[9] = "wxyz";
        
        vector<string> res;
        if(digits.length() == 0) return res;
        
        string t = "";
        permute(0, digits, t, res);
        
        return res;
            
    }
};