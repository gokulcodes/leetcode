class Solution {
public:
    
    int dis(int x1, int x2, int y1, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        
        int mnCost = 0, edges = 0;
        
        vector<bool> isMst(points.size());
        
        while(edges < points.size()){
            auto top = q.top();
            q.pop();
            int w = top.first, p = top.second;
            
            if(isMst[p]) continue;
            
            isMst[p] = true;
            mnCost += w;
            edges++;
            
            for(int i = 0; i < points.size(); i++){
                if(!isMst[i]){
                    int d = dis(points[p][0], points[i][0], points[p][1], points[i][1]);
                    q.push({d, i});
                }
            }
            
        }
        
        return mnCost;
    }
};