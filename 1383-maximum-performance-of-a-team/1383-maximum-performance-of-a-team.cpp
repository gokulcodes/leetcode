int MOD = 1e9 + 7;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<long long, long long>> dic;
        
        for(int i = 0; i < n; i++){
            dic.push_back({speed[i], efficiency[i]});
        }
        
        sort(dic.begin(), dic.end(), [&](auto x, auto y){
           return x.second > y.second; 
        });
        
        long long mx = INT_MIN, sum = 0;
        
        for(int i = 0; i < n; i++){
            
            sum = (sum + dic[i].first);
            pq.push(dic[i].first);
            
            while(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            
            mx = max((sum * dic[i].second), mx);
            
        }
        
        
        return mx % MOD;
    }
};