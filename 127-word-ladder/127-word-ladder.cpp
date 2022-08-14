class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(auto &x : wordList) st.insert(x);
        
        if(st.count(endWord) == 0) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int level = 1;
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string word = q.front();
                q.pop();
                
                for(int j = 0; j < word.size(); j++){
                    string cp = word;
                    for(auto c = 'a'; c <= 'z'; c++){
                        cp[j] = c;
                        if(cp == endWord) return level + 1;
                        if(st.count(cp)){
                            q.push(cp);
                            st.erase(cp);
                        }
                    }
                }
                
            }
            
            level+=1;
        }
        
        return 0;
    }
};