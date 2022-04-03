class Solution {
public:
    void subsets(int index, vector<int>& subs, vector<vector<int>>& comb, vector<int>& v, int k){
        if(subs.size() == k){
            // for(auto x : subs) cout << x << " ";
            // cout << endl;
            comb.push_back(subs);
            return;
        }
        
        if(index >= v.size()) return;
        
        subs.push_back(v[index]);
        subsets(index + 1, subs, comb, v, k);
        subs.pop_back();
        subsets(index + 1, subs, comb, v, k);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v, subs;
        vector<vector<int>> comb;
        
        for(int i = 1; i <= n; i++) v.push_back(i);
        
        subsets(0, subs, comb, v, k);
        return comb;
    }
};