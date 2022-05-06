class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        s.push_back('0');
        
        int last = 1, n = s.length(), j = 0;
        
        for(int i = 0; i < n - 1; i++){
            
            if(last == k){
                last = 1;
                continue;
            }
            
            if(s[i] == s[i + 1]) last++;
            else{
                
                if(j - 1 >= 0 and st[j - 1].first == s[i]){
                    st[j - 1].second += last;
                    
                    if(st[j - 1].second > k)
                        st[j - 1].second -= k;
                    else if(st[j - 1].second == k) st.pop_back(), j--;
                    
                }else{
                    st.push_back({s[i], last});  
                    j++;
                }
                
                last = 1;
            }
            
        }
        
        string res = "";
        
        for(auto x : st){
            res += string(x.second, x.first);
            // cout << x.first << " " << x.second << endl;
        }
        // cout << endl;
        
        return res;
    }
};