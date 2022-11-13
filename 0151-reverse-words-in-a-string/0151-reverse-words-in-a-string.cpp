class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        
        string word = "", res = "";
        while(ss >> word){
            res = word + string(1, ' ') + res;
        }
        
        res.pop_back();
        
        return res;
    }
};