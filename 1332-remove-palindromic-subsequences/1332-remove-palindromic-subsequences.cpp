class Solution {
public:
    bool isPal(string s, int l, int r){
        while(l <= r){
            if(s[l] == s[r]) l++, r--;
            else return false;
        }
        return true;
    }
    
    int removePalindromeSub(string s) {
        if(isPal(s, 0, s.length() - 1)) return 1;
        return 2;
    }
};