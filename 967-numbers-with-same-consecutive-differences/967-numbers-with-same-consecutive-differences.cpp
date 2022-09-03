class Solution {
public:
    vector<int> res;
    void f(int i, string s, int k){
        
        if(i >= s.size()){
            int el = stoi(s);
            res.push_back(el);
            return;
        }
        
        int prev = s[i - 1] - '0';
        int p1 = prev + k, p2 = prev - k;
        
        if(p1 < 10) {
            string s1 = s;
            s1[i] = p1 + '0';
            f(i + 1, s1, k);
        }
        
        if(p1 != p2 and p2 >= 0) {
            string s2 = s;
            s2[i] = p2 + '0';
            f(i + 1, s2, k);
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        string s = string(n, '0');
        
        for(int i = 1; i <= 9; i++){
            s[0] = i + '0';
            f(1, s, k);    
        }
        
        return res;
    }
};