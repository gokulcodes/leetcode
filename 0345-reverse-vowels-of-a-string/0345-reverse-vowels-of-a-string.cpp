class Solution {
public:
    
    bool isVow(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    string reverseVowels(string s) {
        string vows = "";
        
        for(auto &c : s){
            if(isVow(c)) vows=c+vows;
        }
        
        int j = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(isVow(s[i])){
                s[i] = vows[j];
                j++;
            }
        }
        
        return s;
    }
};