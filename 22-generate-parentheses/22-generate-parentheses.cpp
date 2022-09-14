class Solution {
public:
    
    void compute(int n, string& s, int opens, int closes, vector<string>& res){
        if(s.length() == 2 * n) {
            res.push_back(s);
            return;
        }
        
        if(opens < n){
            string pick = s + "(";
            compute(n, pick, opens + 1, closes, res);
        }
        
        if(opens > closes and closes < n){
            string not_pick = s + ")";
            compute(n, not_pick, opens, closes + 1, res);    
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        compute(n, s, 0, 0, res);
        return res;
    }
};