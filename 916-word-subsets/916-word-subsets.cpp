class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<map<char, int>> dic;
        map<char, int> pattern;
        
        for(auto &x : words1){
            
            map<char, int> curr;
            for(auto &y: x) curr[y]++;
            
            dic.push_back(curr);
        }
        
        for(auto &x : words2){
            map<char, int> curr;
            for(auto &y: x) curr[y]++;
            
            for(auto &y: curr) 
                pattern[y.first] = max(pattern[y.first], y.second);
            
        }
        
        vector<string> res;
        
        for(int i = 0; i < dic.size(); i++){
            bool ok = true;
            
            for(auto x : pattern){
                // cout << x.second << " " << dic[i][x.first] << endl;
                if(x.second > dic[i][x.first]){
                    ok = false;
                    break;
                }
            }
            
            // cout << words1[i] << endl;
            if(ok) res.push_back(words1[i]);
            
        }
        
        return res;
    }
};

// l - 1, o - 2, e - 1
