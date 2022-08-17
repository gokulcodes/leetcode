class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dic = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        for(auto &x : words){
            string s = "";
            for(auto &y : x){
                int id = y - 'a';
                s += dic[id];
            }
            st.insert(s);
        }
        
        return st.size();
    }
};