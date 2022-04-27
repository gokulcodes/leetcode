class Solution {
public:
    int find(vector<int>& ds, int i){
        return ds[i] == i ? i : ds[i] = find(ds, ds[i]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        
        vector<int> ds(n);
        
        for(int i = 0; i < n; i++) ds[i] = i;
        
        for(int i = 0; i < pairs.size(); i++){
            int x = find(ds, pairs[i][0]), y = find(ds, pairs[i][1]);
            
            if(x != y){
                ds[y] = x;
            }
        }
        
        vector<vector<int>> m(n);
        for(int i = 0; i < n; i++){
            m[find(ds, ds[i])].push_back(i);
        }
        
        for(auto ids : m){
            string ss;
            for(int i = 0; i < ids.size(); i++){
                ss += s[ids[i]];
            }
            
            sort(ss.begin(), ss.end());
            for(int i = 0; i < ss.size(); i++){
                s[ids[i]] = ss[i];
            }
        }
        return s;
    }
};