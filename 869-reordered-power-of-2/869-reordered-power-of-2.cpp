class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> powers;
        int p = 1;
        
        string dest = to_string(n);
        sort(dest.begin(), dest.end());
        
        while(p <= 1e9){
            string s = to_string(p);
            
            if(dest.size() == s.size()){
                sort(s.begin(), s.end());
                powers.push_back(s);    
            }
            
            p *= 2;
        }
        
        for(auto &x : powers) if(x == dest) return true;
        
        return false;
    }
};