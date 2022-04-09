class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        
        for(auto x : nums){
            freq[x]++;
        }
        
        vector<pair<int, int>> cnt;
        for(auto x : freq){
            cnt.push_back({x.first, x.second});
        }
        
        sort(cnt.begin(), cnt.end(), [&](auto a, auto b){
            return a.second > b.second; 
        });
        
        vector<int> kfreq;
        for(int i = 0; i < cnt.size() && k > 0; i++, k--){
            kfreq.push_back(cnt[i].first);
        }
        
        return kfreq;
    }
};