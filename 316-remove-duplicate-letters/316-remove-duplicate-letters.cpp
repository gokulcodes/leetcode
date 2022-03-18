class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, bool> visited;
        map<char, int> cnt;
        string res = "0";
        
        for(auto c : s) cnt[c]++;
        
        for(auto c : s){
            cnt[c]--;
            if(visited[c]) continue;
            while(c < res.back() && cnt[res.back()]){
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        
        return res.substr(1);
    }
};