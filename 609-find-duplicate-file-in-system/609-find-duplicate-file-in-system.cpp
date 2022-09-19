class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int n = paths.size();
        vector<vector<string>> res;
        
        map<string, vector<string>> mp;
        
        for(int i = 0; i < n; i++){
            
            istringstream ss(paths[i]);
            string del, key = "";
            
            while(getline(ss, del, ' ')) {
                
                if(key == "") key = del;
                else{
                    
                    string full = key + "/" + del, el, pathKey = "";
                    
                    istringstream st(full);
                    
                    while(getline(st, el, '(')){
                        if(pathKey == "") pathKey = el;
                        else{
                            el.pop_back();
                            mp[el].push_back(pathKey);
                        }
                    }
                    
                }
                
            }
            
        }
        
        for(auto &x : mp) if(x.second.size() > 1) res.push_back(x.second);
        
        return res;
    }
};