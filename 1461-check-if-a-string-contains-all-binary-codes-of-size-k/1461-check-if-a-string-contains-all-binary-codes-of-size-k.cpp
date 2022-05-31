class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        set<string> st;
        
        for(int i = 0; i < n; i++){
            string t = s.substr(i, k);
            if(t.size() == k) st.insert(t);
            // cout << t << endl;
        }
        cout << st.size() << ' ' << pow(2, k) << endl;
        return st.size() == pow(2, k);
    }
    
};