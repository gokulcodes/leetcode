class Solution {
public:
    
    string recur(string s, int n){
        if(n == 1) return s;
        
        string newS = "";
        
        for(int i = 0; i < s.length(); i++){
            int cnt = 0, j = i;
            
            while(j < s.size() && s[i] == s[j])
                cnt++, j++;
            
            newS += (to_string(cnt) + string(1, s[i]));
            
            i = j - 1;
        }
        
        return recur(newS, n - 1);
        
    }
    
    string countAndSay(int n) {
        return recur("1", n);
    }
};