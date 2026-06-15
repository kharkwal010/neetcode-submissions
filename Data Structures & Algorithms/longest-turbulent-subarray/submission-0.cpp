class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int start = 0;
        int ans = 1;
        bool fall;
        
        for(int end = 1; end<arr.size(); end++){
            if(arr[end]==arr[start]){
                start=end;
                continue;
            }
            if(arr[end]<arr[start]){
                fall = false;
            }
            else fall = true;
            while(end<arr.size()-1){
                if(fall){
                    if(arr[end+1]<arr[end]){
                        end++;
                        fall = false;
                    }
                    else break;
                }
                else{
                    if(arr[end+1]>arr[end]){
                        end++;
                        fall = true;
                    }
                    else break;
                }
            }
            ans = max(end - start + 1, ans);
            start = end;

        }
        return ans;
    }
};