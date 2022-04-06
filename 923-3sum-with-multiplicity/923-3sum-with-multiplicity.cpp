class Solution {
public:
    int MOD = 1e9 + 7;
    
    int threeSumMulti(vector<int>& arr, int target) {
        map<long long, long long> count;
        
        for(auto x : arr) count[x]++;
        
        long long ans = 0;
        
        for(int i = 0; i <= 100; i++){
            for(int j = i + 1; j <= 100; j++){
                int z = target - i - j;
                if(j < z && z <= 100){
                    ans += count[i] * count[j] * count[z];
                    ans %= MOD;
                }
            }
        }
        
        for(int i = 0; i <= 100; i++){
            int z = target - 2 * i;
            if(i < z and z <= 100){
                ans += count[i] * (count[i] - 1) / 2 * count[z];
                ans %= MOD;
            }
        }
        
        for(int x = 0; x <= 100; x++){
            if(target % 2 == x % 2){
                int y = (target - x) / 2;
                if(x < y and y <= 100){
                    ans += count[x] * count[y] * (count[y] - 1) / 2;
                    ans %= MOD;   
                }
            }
        }
        
        if(target % 3 == 0){
            int x = target / 3;
            if(0 <= x && x <= 100){
                ans += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                ans %= MOD;
            }
        }
        
        return (int)ans;
    }
};