class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0;
        
        set<int> evenIndex;
        
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                evenIndex.insert(i);
                sum += nums[i];
            }
        }
        
        vector<int> res;
        
        for(int i = 0; i < queries.size(); i++){
            
            int value = queries[i][0], index = queries[i][1];
            int curr = nums[index] + value;
            
            if(abs(curr) % 2 == 0) {
                
                if(evenIndex.count(index)) 
                    sum -= nums[index], sum += curr;
                else 
                    sum += curr;
                
                evenIndex.insert(index);
                
            }else{
                
                if(evenIndex.count(index)) 
                    sum -= nums[index], evenIndex.erase(index);
                
            }
            
            nums[index] = curr;
            res.push_back(sum);
            
        }
        
        return res;
    }
};