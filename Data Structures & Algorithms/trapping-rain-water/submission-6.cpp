class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxl(height.size(),0);
        vector<int> maxr(height.size(),0); 
        int maxv = 0;    
        for(int i=0; i<height.size(); i++){
            maxl[i] = maxv;
            maxv = max(maxv, height[i]);
        }
        maxv = 0;
        for(int i=height.size()-1; i>=0; i--){
            maxr[i]=maxv;
            maxv = max(maxv, height[i]);
        } 
        int volume = 0;
        for(int i=0; i<height.size(); i++){
            int value = min(maxr[i], maxl[i]) - height[i];
            
            if(value<0){
                value = 0;
            }
            volume = volume + value;
        }   
        return volume;    
    }
};
