class Solution {
public:
    
    int count(int num){
        if(num == 0) return 0;
        return 1 + (num % 2 ? count(num - 1) : count(num >> 1));
    }
    
    int numberOfSteps(int num) {
        return count(num);
    }
};