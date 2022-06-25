class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int, vector<int>> adj;
        vector<int> freq(n);
        vector<pair<int, int>> arr;
        map<int, int> weight;
        
        for(auto x : roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        for(auto x : adj){
            freq[x.first] = x.second.size();
        }
        
        for(int i = 0; i < freq.size(); i++){
            arr.push_back({ i, freq[i] });
        }
        
        sort(arr.begin(), arr.end(), [&](auto x, auto y){
           return x.second < y.second; 
        });
        
        int i = 1;
        
        for(auto &x : arr){
            weight[x.first] = i;
            i++;
        }
        
        long long total = 0;
        for(auto x : roads){
            total += weight[x[0]] + weight[x[1]];
        }
        
        return total;
    }
};