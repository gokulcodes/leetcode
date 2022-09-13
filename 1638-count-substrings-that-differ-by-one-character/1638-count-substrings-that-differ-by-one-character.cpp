class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length(), m = t.length(), total = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                
                for(int k = 0; k < min(n, m); k++){
                    
                    if(i + k >= n or j + k >= m) break;
                    
                    if(s[i + k] != t[j + k])
                        cnt++;
                    
                    if(cnt == 1)
                        total += 1;
                    
                }
                
            }
            
        }
        
        return total;
    }
};