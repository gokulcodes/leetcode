class Solution {
public:
    // O(n * m) Time | O(26) + O(26) space
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        for(auto &x : words){
            map<char, char> u = {}, v = {};
            
            bool flag = true;
            
            for(int i = 0; i < x.size(); i++){
                
                char curr = x[i], p = pattern[i];
                
                if((u.find(curr) == u.end() and v.find(p) == v.end()) || (v[p] == curr and u[curr] == p)){
                    
                    u[curr] =  p;
                    v[p] = curr;    
                    
                }else{
                    
                    flag = false;
                    break;
                    
                }
                
            }
            
            if(flag) res.push_back(x);
        }
        
        return res;
    }
};