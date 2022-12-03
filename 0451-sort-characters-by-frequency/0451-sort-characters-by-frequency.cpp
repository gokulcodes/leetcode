class Solution {
public:
    string frequencySort(string s) {
        map<char, int> hash;
        for(auto &x : s) hash[x]++;
        string res = "";
        priority_queue<pair<int, char>> pq;
        
        for(auto x : hash){
            pq.push({x.second, x.first});
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            res += string(top.first, top.second);
            pq.pop();
        }
        
        return res;
    }
};