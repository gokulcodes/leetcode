class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        
        for(int i = 0; i < n; i++) reverse(words[i].begin(), words[i].end());
        sort(words.begin(), words.end());
        map<string, vector<string>> table;
        map<string, bool> marked;
        
        for(int i = 0; i < n; i++){
            
            for(int j = n - 1; j >= i; j--){
                
                if(i == j) continue;
                string pref = words[j].substr(0, words[i].size());
                
                if(pref == words[i]){
                    table[words[j]].push_back(words[i]);
                    marked[words[j]] = true;
                    marked[words[i]] = true;
                    break;
                }
                
            }
            
        }
        
        int len = 0;
        for(auto x : table){
            len += x.first.size() + 1;
        }
        
        for(auto x : words){
            if(marked[x] == false)
                len += x.size() + 1;
        }
        
        return len;
    }
};