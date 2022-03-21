class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            m[s[i]] = i;
        }
        
        vector<int> res;
        for(int i = 0; i < s.length(); i++){
            int last = m[s[i]], j = i;
            for(j = i; j <= last; j++){
                if(last < m[s[j]]){
                    last = m[s[j]];
                }
            }
            res.push_back(last - i + 1);
            i = j - 1;
        }
        
        return res;
    }
};