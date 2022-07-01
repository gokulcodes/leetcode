class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](auto x, auto y){
           return x[1] > y[1]; 
        });
        
        int units = 0, boxes = truckSize;
        for(int i = 0; i < boxTypes.size(); i++){
            
            auto x = boxTypes[i];
            
            if(boxes <= 0) break;
            
            units += x[1] * min(boxes, x[0]);
            boxes -= min(boxes, x[0]);
            
        }
        
        return units;
    }
};