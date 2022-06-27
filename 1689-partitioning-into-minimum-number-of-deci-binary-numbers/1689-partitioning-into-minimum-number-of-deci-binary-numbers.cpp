class Solution {
public:
    int minPartitions(string n) {
        int mx = INT_MIN;
        for(auto x : n){
            mx = max(x - '0', mx);
        }
        return mx;
    }
};