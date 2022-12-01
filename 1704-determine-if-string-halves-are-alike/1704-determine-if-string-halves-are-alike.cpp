#include <bits/stdc++.h>

class Solution {
public:
    
    bool vowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
    bool halvesAreAlike(string s) {
        map<int, int> hash;
        int last = 0;
        for(int i = 0; i < s.length(); i++){
            if(vowel(s[i])){
                hash[i + 1] = ++last;
            }else{
                hash[i + 1] = last;
            }
        }
        int n = s.length();
        
        return hash[n / 2] == (hash[n] - hash[n / 2]);
        
    }
};