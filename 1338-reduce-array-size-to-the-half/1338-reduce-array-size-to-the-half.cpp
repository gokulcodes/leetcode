class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> freq;
        for(auto x : arr) freq[x]++;
        
        
        vector<pair<int, int>> hash;
        for(auto x : freq) hash.push_back({x.first, x.second});
        
        sort(hash.begin(), hash.end(), [&](auto x, auto y){
            return x.second > y.second;
        });
        
        int total = arr.size(), res = 0;
        
        for(int i = 0; i < hash.size(); i++){
            total -= hash[i].second;
            res++;
            if(total <= arr.size() / 2){
                break;
            }
        }
        
        return res;
    }
};