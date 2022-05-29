class Solution {
public:
    
    bool comp(string a, string b){
        for(int i = 0; i < min(a.size(), b.size()); i++){
            if(a[i] == '1' and b[i] == '1'){
                return false;
            }
        }
        
        return true;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size(), mx = INT_MIN;
        
        map<int, int> dic;
        
        for(int i = 0; i < n; i++){
            long long t = 0;
            
            for(auto x : words[i]){
                int i = x - 'a';
                t |= 1 << i;
            }
            
            dic[i] = t;
        }
        
        for(auto x : dic) cout << x.second << endl;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                if((dic[i] & dic[j]) == 0){
                    mx = max(int(words[i].size() * words[j].size()), mx);
                }
                
            }
        }
        
        
        return max(mx, 0);
    }
};