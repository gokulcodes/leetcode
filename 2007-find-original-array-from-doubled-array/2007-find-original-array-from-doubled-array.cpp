class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        if(n % 2) return {};
        
        map<int, int> hash;
        for(auto x : changed) hash[x]++;
        
        vector<int> found;
        
        sort(changed.begin(), changed.end());
        
        for(auto x : changed){
            if(hash[x] == 0) continue;
                
            int doubled = 2 * x;
            
            if(x == doubled and hash[x] >= 2){
                found.push_back(x);
                hash[x]--;
                hash[doubled]--;
                continue;
            }
            
            if(x != doubled and hash[doubled] > 0) {
                found.push_back(x);
                hash[x]--;
                hash[doubled]--;
            }
            
        }
        
        if(found.size() != n / 2) return {};
        
        return found;
    }
};