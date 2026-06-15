class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size(),0);
        vector<int> right_max(height.size(),0);
        int left = 0;
        for(int i=1; i<height.size(); i++){
            left = max(left, height[i-1]);
            left_max[i]= left;
        }
        int right = 0;
        for(int i=height.size()-2; i>=0; i--){
            right = max(right, height[i+1]);
            right_max[i]=right;
        }
        int water = 0;
        for(int i=0;i<height.size(); i++){
            int layer = min(left_max[i], right_max[i]) - height[i];
            if(layer>0){
                water = water + layer;
            }
        }
        return water;                
    }
};
