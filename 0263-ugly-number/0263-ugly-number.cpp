class Solution {
public:
    
    
    
    bool isUgly(int n) {
        if(n <= 0) return false;
        
        while(n % 2 == 0){
            n = n / 2;
        }
        
        for(int i = 3; i <= sqrt(n); i += 2){
            // cout << n << " " << i << endl;
            while(n % i == 0){
                
                if(i != 2 and i != 3 and i != 5) 
                    return false;
                
                n = n / i;
            }
            
        }
        
        if(n > 5) return false;
       
        return true;
    }
};