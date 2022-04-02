class Solution {
public:
    
    bool checkPal(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1, inv = 0;
        
        while(l < r){
            
            if(s[l] != s[r]){
                return checkPal(s, l + 1, r) || checkPal(s, l, r - 1);
            }
            
            l++, r--;
            
        }
        
        return true;
    }
};