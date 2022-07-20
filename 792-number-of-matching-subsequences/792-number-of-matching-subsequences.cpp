class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> indices;
        
        for(int i = 0; i < s.size(); i++){
            indices[s[i]].push_back(i);
        }
        
        int cnt = 0;
        for(auto x : words){
            bool ok = true;
            
            int last = 0;
            
            for(int i = 0; i < x.size(); i++){
                char c = x[i];
                
                auto it = lower_bound(indices[c].begin(), indices[c].end(), last);
                if(it == indices[c].end()){
                    
                    ok = false;
                    break;
                    
                }else{
                    
                    last = *it + 1;
                    
                }
                
            }
            
            // if(ok) cout << x << endl;
            cnt += ok;
            
        }
        
        return cnt;
    }
};