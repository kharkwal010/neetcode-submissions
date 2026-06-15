class Solution {
public:
    int trap(vector<int>& height) {
       int left = 0;
       vector<int> mleft(height.size(),0);
       for(int i=0; i<height.size(); i++){
            mleft[i] = left;
            left = max(left, height[i]);
       } 

        int right = 0;
       vector<int> mright(height.size(),0);
       for(int i=height.size()-1; i>=0; i--){
            mright[i] = right;
            right = max(right, height[i]);
       } 

       int ans=0;
       for(int i=0; i<height.size(); i++){
            ans += max(0, min(mleft[i], mright[i])-height[i]);
       }
       return ans;
    }
};
