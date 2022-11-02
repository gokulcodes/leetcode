class Solution {
public:
    
    int bfs(string& start, string& end, vector<string>& bank){
        
        queue<pair<string, int>> q;
        int changes = 0;
        
        q.push({start, 0});
        
        while(!q.empty()){
            
            string top = q.front().first;
            int cnt = q.front().second;
            
            // cout << top << " " << cnt << endl;
            
            if(top == end) return cnt;
            q.pop();
            
            for(auto &x : bank){
                
                int muts = 0;
                
                for(int i = 0; i < 8; i++){
                    
                    if(top[i] != x[i]){
                        muts++;
                    }
                
                } 
                                
                if(muts == 1) {
                    q.push({x, cnt + 1});
                    x = "0";
                }
                
                // for(auto &y : bank) cout << y << " ";
                // cout << top << " " << q.size() << endl;
                
            }
            
            
        }
        
        return -1;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        
        return bfs(start, end, bank);
    }
};