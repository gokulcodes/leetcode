class NumArray {
public:
    vector<int> fen, arr;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        fen.resize(n + 1, 0);
        for(int i = 0; i < n; i++){
            init(i, nums[i]);
        }
        cout << endl;
    }
    
    void init(int i, int val){
        i++;
        
        while(i <= n){
            fen[i] += val;
            i += (i & (-i));
        }
        
        // for(auto x : fen) cout << x << " ";
        // cout << endl;
        
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        init(index, diff);
    }
    
    int sumRange(int left, int right) {
        
        int sum1 = 0, i = right + 1, j = left, sum2 = 0;
        
        while(i > 0){
            sum1 += fen[i];
            i = i - (i & (-i));
        }
        
        while(j > 0){
            sum2 += fen[j];
            j = j - (j & (-j));
        }
        // cout << sum1 << " " << sum2 << endl;
        return sum1 - sum2;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */