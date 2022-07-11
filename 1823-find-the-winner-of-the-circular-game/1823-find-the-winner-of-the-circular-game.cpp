class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> vis(n + 1);
        vector<int> arr(n + 1);
        for(int i = 1; i <= n; i++) arr[i] = i;
        
        int last = 1, deleted = n;
        
        while(deleted > 1){
            
            int cnt = k, i = last;
            
            while(vis[i] == true) {
                i += 1;
                i %= n + 1;
                if(i == 0) i++;
            }
            
            while(cnt > 1){
                if(vis[i] == true) {
                    i += 1;
                    i %= n + 1;
                    if(i == 0) i++;
                    continue;
                }
                
                cnt--;
                i += 1;
                i %= n + 1;
                if(i == 0) i++;
            }
            
            while(vis[i] == true) {
                i += 1;
                i %= n + 1;
                if(i == 0) i++;
            }
            
            vis[i] = true;
            deleted--;
            last = i;
        }
        
        int res;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                res = i;
                break;
            }
        }
        
        return res;
    }
};

// 2 % 5 = 2
// 2 % 4 = 3
// 2 % 3 = 
