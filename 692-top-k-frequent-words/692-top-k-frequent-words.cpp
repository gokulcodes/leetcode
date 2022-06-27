class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hash;
        for(auto x : words){
            hash[x]++;
        }
        
        vector<pair<string, int> > p;
        for(auto x : hash){
            p.push_back({x.first, x.second});
        }
        
        sort(p.begin(), p.end(), [&](auto x, auto y){
           return x.second == y.second ? x.first < y.first : x.second > y.second; 
        });
        
        vector<string> res;
        for(int i = 0; i < k; i++){
            res.push_back(p[i].first);
        }
        
        return res;
    }
};