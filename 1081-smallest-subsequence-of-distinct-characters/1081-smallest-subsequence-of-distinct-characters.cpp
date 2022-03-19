class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        map<char, int> cnt;
        map<char, bool> visited;
        
        for(auto c : s) cnt[c]++;
        
        for(auto c : s){
            cnt[c]--;
            if(visited[c]) continue;
            while(!st.empty() && c < st.top() && cnt[st.top()]){
                visited[st.top()] = false;
                st.pop();
            }
            st.push(c);
            visited[c] = true;
        }
        
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};