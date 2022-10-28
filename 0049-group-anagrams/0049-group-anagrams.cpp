class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash;
        
        for(auto &x : strs){
            string sorted = x;
            sort(sorted.begin(), sorted.end());
            hash[sorted].push_back(x);
        }
        
        vector<vector<string>> res;
        
        for(auto &x : hash){
            res.push_back(x.second);
        }
        
        return res;
        
    }
};