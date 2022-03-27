class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<vector<int>, pair<int, int>>> m;
        for(int i = 0; i < mat.size(); i++){
            int soldiers = 0;
            for(int j = 0; j < mat[i].size(); j++){
                soldiers += mat[i][j];
            }
            m.push_back({mat[i], {soldiers, i}});
        }
        
        sort(m.begin(), m.end(), [&](auto a, auto b){
            return a.second.first == b.second.first ? a.second.second < b.second.second : a.second.first < b.second.first;
        });
        
        // for(auto x : m){
        //     cout << x.second.first << " " << x.second.second << endl;
        // }
        
        vector<int> res;
        for(int i = 0; i < m.size() && k > 0; i++, k--){
            res.push_back(m[i].second.second);
        }
        
        return res;
        
    }
};