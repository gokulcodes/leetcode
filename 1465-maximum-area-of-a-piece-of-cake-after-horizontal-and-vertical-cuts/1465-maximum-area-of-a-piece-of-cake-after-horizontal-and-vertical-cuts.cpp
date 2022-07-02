class Solution {
public:
    
    long long MOD = 1e9 + 7;
    
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0);
        sort(hc.begin(), hc.end());
        vc.push_back(0);
        sort(vc.begin(), vc.end());
        
        if(hc.back() != h) hc.push_back(h);
        if(vc.back() != w) vc.push_back(w);
        
        pair<int, int> f, s;
        int diff = INT_MIN;
        
        for(int i = 1; i < hc.size(); i++){
            if(hc[i] - hc[i - 1] > diff){
                diff = hc[i] - hc[i - 1];
                f = {hc[i], hc[i - 1]};
            }
        }
        
        diff = INT_MIN;
        
        for(int i = 1; i < vc.size(); i++){
            if(vc[i] - vc[i - 1] > diff){
                diff = vc[i] - vc[i - 1];
                s = {vc[i], vc[i - 1]};
            }
        }
        
        // cout << f.first << " " << f.second << endl;
        // cout << s.first << " " << s.second << endl;
        
        return (((s.second - s.first) % MOD) * ((f.second - f.first) % MOD)) % MOD;
    }
};