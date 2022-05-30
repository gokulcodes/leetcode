class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long r = dividend / divisor;
        
        return r > INT_MAX ? INT_MAX : r < INT_MIN ? INT_MIN : int(r);
    }
};