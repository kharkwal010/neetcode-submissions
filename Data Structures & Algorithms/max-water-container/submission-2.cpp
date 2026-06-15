class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int ans = 0;
        while(left<right){
            ans = max((right-left)*min(heights[right], heights[left]),ans);
            if(heights[right]>heights[left]){
                left++;
            }
            else right--;
        }
        return ans;
        
    }
};
