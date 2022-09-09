class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [&](auto &x, auto &y){
           return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];
        });
        
        int n = properties.size(), mx = INT_MIN, ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(mx > properties[i][1]){
                ans++;
            }
            mx = max(properties[i][1], mx);
        }
        
        return ans;
    }
};