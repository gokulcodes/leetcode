class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        
        string res = "";
        
        while(!pq.empty()){
            
            if(pq.size() >= 2){
                
                auto first = pq.top();
                pq.pop();
                auto second = pq.top();
                pq.pop();
                
                if(first.first and res.back() != first.second){
                    
                    res += string(min(first.first, 2), first.second);
                    first.first -= min(first.first, 2);
                    
                }
                
                if(second.first and res.back() != second.second){
                    
                    res += string(min(second.first, 1), second.second);
                    second.first -= min(second.first, 1);
                    
                }

                if(first.first) pq.push(first);
                if(second.first) pq.push(second);
                
            }else{
                
                auto first = pq.top();
                pq.pop();
                
                if(res.back() == first.second) {
                    pq.push(first); 
                    break;
                }
                
                res += string(min(first.first, 2), first.second);
                first.first -= min(first.first, 2);
                
                if(first.first) pq.push(first);
                
                break;
            }
            
        }
        
        
        if(!pq.empty() && pq.top().first){
            res += string(min(pq.top().first, (res.back() == pq.top().second ? 1 : 2)), pq.top().second);
        }
        
        int uniq = 0;
        for(int i = res.size() - 1; i >= 0; i--){
            if(res.back() == res[i]) uniq++;
            else break;
        }
        
        if(uniq >= 3) res.pop_back();
        
        return res;
        
    }
};