class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        
        string res = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ']'){
                st.push(string(1, s[i]));
                continue;
            }
            
            string t = "";
            while(!st.empty() && st.top() != "["){
                t = st.top() + t;
                st.pop();
            }
            
            st.pop();
            
            string times = "";
            while(!st.empty() && st.top() >= "0" && st.top() <= "9"){
                times = st.top() + times;
                st.pop();
            }
            
            int cnt = stoi(times);
            
            string newS = "", repeat = "";
            while(!st.empty() && st.top() != "["){
                newS = st.top() + newS;
                st.pop();
            }
            
            for(int j = 1; j <= cnt; j++) repeat += t;
            
            st.push(newS + repeat);
            
        }
        
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};

// bcbc
