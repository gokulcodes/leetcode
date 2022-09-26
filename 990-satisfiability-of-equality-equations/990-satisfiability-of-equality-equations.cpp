class Solution {
public:
    vector<int> ds;
    
    int find(int i){
        
        if(ds[i] != i) 
            ds[i] = find(ds[i]);
        
        return ds[i];
    }
    
    void uunion(int a, int b){
        
        int roota = find(a);
        int rootb = find(b);
        
        ds[roota] = rootb;
        
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        ds.resize(26, 0);
        
        for(int i = 0; i < 26; i++){
            ds[i] = i;
        }
        
        for(auto &x : equations){
            if(x[1] == '!')
                continue;
            
            uunion(x[0] - 'a', x[3] - 'a');
            
        }
        
        for(auto &x : equations){
            if(x[1] != '!')
                continue;
            
            if(find(x[0] - 'a') == find(x[3] - 'a'))
                return false;
            
        }
        
        return true;
    }
};