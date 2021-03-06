class Solution {
public:
    
    int min(int a, int b){
        return a >= b ? b : a;
    }
    
    int minDeletions(string s) {
        map<char, int> mp;
        map<int, int> freq;
        
        for(auto x : s) mp[x]++;
        
        for(auto x : mp) freq[x.second]++;
        
        int res = 0;
        
        for(auto x = freq.rbegin(); x != freq.rend(); x++){
            
            int i = 1;
            
            while(x->second > 1){
                
                if(x->first - i > 0) {
                    freq[x->first - i]++;
                }
                
                res += min(x->first, i);
                
                x->second--;
                i++;
            }
            
        }
        
        return res;
    }
};
