struct comparator{
    bool operator()(pair<int, int> i, pair<int, int> j){
        return i.second < j.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        
        for(auto x : nums){
            freq[x]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> q;
        for(auto x : freq){
            q.push({x.first, x.second});
        }
        
        vector<int> kfreq;
        while(!q.empty() && k--){
            kfreq.push_back(q.top().first);
            q.pop();
        }
        
        return kfreq;
    }
};