class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        map<string, vector<string>> table;
        vector<vector<string>> res;
        
        sort(products.begin(), products.end());
        
        string prefix = string(1, searchWord[0]), lastPrefix = string(1, searchWord[0]);
        
        for(auto x : products){
            if(x[0] == searchWord[0]) {
                table[string(1, searchWord[0])].push_back(x);    
            }
        }
        
        vector<string> temp;
        for(int i = 0; i < min(3, int(table[prefix].size())); i++) 
            temp.push_back(table[prefix][i]);
        
        res.push_back(temp);
        
        for(int i = 1; i < searchWord.size(); i++){
            
            prefix += string(1, searchWord[i]);
            
            for(auto y : table[lastPrefix]){
                
                string pref = y.substr(0, prefix.size());
                
                if(pref == prefix){
                    table[prefix].push_back(y);
                }
                
            }
            
            vector<string> temp;
            for(int i = 0; i < min(3, int(table[prefix].size())); i++) 
                temp.push_back(table[prefix][i]);
            
            res.push_back(temp);
            lastPrefix = prefix;
        }
        
        return res;
    }
};