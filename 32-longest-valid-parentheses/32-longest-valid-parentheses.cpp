class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st;
        
        int last = -1, best = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                int run = 0;
                if(st.size() > 0){
                    st.pop();
                    if(st.size() == 0){
                        run = i - last;    
                    }else{
                        run = i - st.top();
                    }
                    
                    best = max(best, run);    
                }else{
                    last = i;
                }
            }
        }
        
        return best;
    }
};