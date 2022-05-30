class Solution {
public:
    int divide(long long dividend, long long divisor) {
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long qn = 0, temp = 0;
        
        for(int i = 31; i >= 0; i--){
            if(temp + (divisor << i) <= dividend){
                temp += (divisor << i);
                qn |= (1LL << i);
            }
        }
        
        return (qn * sign) > INT_MAX ? INT_MAX : (qn * sign) < INT_MIN ? INT_MIN : (qn * sign);
    }
};