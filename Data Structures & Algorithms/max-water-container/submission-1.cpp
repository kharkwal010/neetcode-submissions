class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int area =0;
        while(left<right){
            int amax = (right-left)*(min(heights[left], heights[right]));
            area = max(area, amax);
            int left_height = heights[left];
            int right_height = heights[right];
            if (heights[left]<=heights[right]){
                left++;
                while(left<right && heights[left]<left_height){
                    left++;
                }
            }
            else if (heights[right]<heights[left]){
                right--;
                while(left<right && heights[right]<right_height){
                    right--;
                }
            }
        
        }
        return area;
        
    }
};
