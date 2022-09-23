int MOD = 1e9 + 7;

class Solution {
public:
    
    int bits(int n){
        return log2(n) + 1;
    }
    
    int concatenatedBinary(int n) {
        long long total = 0;
        
        for(int i = 1; i <= n; i++){
            
            int len = bits(i);
            total = (((total << len) % MOD) + i) % MOD;
            
        }
        
        return total;
    }
};