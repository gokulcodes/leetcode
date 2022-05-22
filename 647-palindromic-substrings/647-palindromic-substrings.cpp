class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), total = 0;
        
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            
            while(l >= 0 and r < n and s[l] == s[r]){
                l--, r++;
                total++;
            }
        }
        
        for(int i = 0; i < n - 1; i++){
            int l = i, r = i + 1;
            
            while(l >= 0 and r < n and s[l] == s[r]){
                l--, r++;
                total++;
            }
        }
        
        return total;
    }
};