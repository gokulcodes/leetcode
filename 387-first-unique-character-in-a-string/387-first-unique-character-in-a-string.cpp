class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> dic;
        for(int i = 0; i < s.length(); i++){
            auto prev = dic[s[i]];
            dic[s[i]] = {prev.first + 1, i};
        }
        
        int res = INT_MAX;
        for(auto x : dic){
            auto info = x.second;
            if(info.first == 1) {
                res = min(res, info.second);
            }
        }
            
        return res == INT_MAX ? -1 : res;
    }
};