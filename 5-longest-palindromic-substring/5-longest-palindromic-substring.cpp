class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), mx = INT_MIN;
        
        // if(n == 1) return s;
        
        string res = "";
        
        for(int i = 0; i < n; i++){
            int l = i - 1, r = i + 1;
            
            while(l >= 0 and r < n){
                if(s[l] == s[r]){
                    l--, r++;
                }else break;
            }
            
            l++, r--;
            // cout << l << " " << r << " " << r - l + 1 << endl;
            
            if(mx < r - l + 1){
                mx = r - l + 1;
                res = s.substr(l, mx);
            }
            
            l = i, r = i + 1;
            while(l >= 0 and r < n){
                if(s[l] == s[r]){
                    l--, r++;
                }else break;
            }
            l++, r--;
            
            if(mx < r - l + 1){
                mx = r - l + 1;
                res = s.substr(l, mx);
            }
            
        }
        
        return res;
    }
};