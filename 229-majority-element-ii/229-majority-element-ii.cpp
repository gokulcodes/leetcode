class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, n = nums.size();
        
        if(n == 1) return nums;
        
        int m1 = nums[0], m2 = INT_MAX;
        
        for(int i = 0; i < n; i++){
            if(nums[i] != m1) {
                m2 = nums[i];
                break;
            }
        }
        
        if(m2 == INT_MAX) return {m1};
        
        for(int i = 0; i < n; i++){
            if(nums[i] == m1){
                cnt1++;
            }else if(nums[i] == m2){
                cnt2++;
            }else if(cnt1 == 0){
                m1 = nums[i];
                cnt1++;
            }else if(cnt2 == 0){
                m2 = nums[i];
                cnt2++;
            }else{
                cnt1--, cnt2--;
            }
            
        }
        
        cout << m1 << " " << m2 << endl;
        
        vector<int> res;
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == m1) cnt1++;
            else if(nums[i] == m2) cnt2++;
        }
        
        if(cnt1 > n / 3) res.push_back(m1);
        if(cnt2 > n / 3) res.push_back(m2);
        
        return res;
    }
};