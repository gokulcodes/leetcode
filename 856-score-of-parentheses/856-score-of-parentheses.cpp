class Solution {
public:
    int toInt(string s){
        return stoi(s);
    }
    
    int scoreOfParentheses(string s) {
        stack<string> st;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(string(1, s[i]));
                continue;
            }

            if(st.top() != "("){
                int curr = toInt(st.top());
                curr *= 2;
                st.pop();
                st.pop();
                if(!st.empty() && st.top() != "(") {
                    curr += toInt(st.top()), st.pop();
                }
                st.push(to_string(curr));
            }else if(st.top() == "("){
                st.pop();
                int t = 1;
                if(!st.empty() && st.top() != "(") t = toInt(st.top()) + 1, st.pop();
                st.push(to_string(t));
            }
        }
        
        return toInt(st.top());
    }
};