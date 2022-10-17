class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> hash;
        for(auto &c : sentence) hash.insert(c);
        
        for(auto c = 'a'; c <= 'z'; c++){
            if(hash.count(c) == 0) return false;
        }
        
        return true;
    }
};