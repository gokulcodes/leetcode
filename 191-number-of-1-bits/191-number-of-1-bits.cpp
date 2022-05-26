class Solution {
public:
    
    int countBits(uint32_t n){
        if(n == 0) return 0;
        return (n % 2) + countBits(n / 2);
    }
    
    int hammingWeight(uint32_t n) {
            
        // int bits = 0;
        // while(n > 0){
        //     if(n & 1) bits++;
        //     n /= 2;
        // }
        
        return countBits(n);
    }
};