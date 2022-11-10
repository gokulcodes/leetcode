class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        string res = "";
        
        for(int i = 0; i < s.length(); i++){
            
            int flag = 0;
            
            while(!st.empty() and st.top() == s[i]){
                flag = 1;
                st.pop();
            }
            
            if(!flag) st.push(s[i]);
            
        }
        
        while(!st.empty()){
            res = string(1, st.top()) + res;
            st.pop();
        }
        
        return res;
    }
};