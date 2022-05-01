class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "", b = "";
        
        for(auto x : s){
            if(x == '#') {
                if(a.length())
                    a.pop_back();
            }
            else a += string(1, (x));
            // cout << a << endl;
        }
        
        
        for(auto x : t){
            if(x == '#') {
                if(b.length())
                    b.pop_back();
            }
            else b += string(1, (x));
        }
        
        // cout << a << " " << b << endl;
        
        return a == b;
    }
};