class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hash;
        for(auto &x : words) hash[x]++;
        
        vector<pair<string, int>> pr;
        for(auto &x : hash) pr.push_back({x.first, x.second});
        
        sort(pr.begin(), pr.end(), [&](auto x, auto y){
            return x.second == y.second ? x.first < y.first : x.second > y.second;
        });
        
        vector<string> res;
        for(int i = 0; i < pr.size() && k > 0; i++) res.push_back(pr[i].first), k--;
        
        return res;
    }
};