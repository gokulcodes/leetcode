class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1, inv = 0;
        
        while(l <= r){
            if(s[l] == s[r]){
                l++, r--;
            } else if(s[l] != s[r]) {
                
                if(s[l + 1] == s[r]) l++;
                else {
                    inv = 1000;
                    break;
                }
                
                inv++;
                
            }
            
        }
        
        if(inv <= 1) return true;
        
        l = 0, r = s.length() - 1, inv = 0;
        while(l <= r){
            if(s[l] == s[r]){
                l++, r--;
            } else if(s[l] != s[r]) {
                
                if(s[l] == s[r - 1]) r--;
                else {
                    inv = 1000;
                    break;
                }
                
                inv++;
                
            }
            
        }
        
        return inv <= 1;
    }
};