class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> hash;
        for(auto &x : arr) hash[x]++;
        
        map<int, int> hhash;
        for(auto &x : hash) {
            hhash[x.second]++;
            if(hhash[x.second] > 1) return false;
        }
        
        return true;
    }
};