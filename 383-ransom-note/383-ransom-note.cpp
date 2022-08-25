class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> freq;
        for(auto &x : magazine) freq[x]++;
        
        for(auto &x : ransomNote){
            if(freq[x] > 0) freq[x]--;
            else return false;
        }
        
        return true;
    }
};