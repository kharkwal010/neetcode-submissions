class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int start = 0;
        int end = k;
        while(end<arr.size()){
            if(abs(x-arr[start])>abs(x-arr[end])){
                start++;
                end++;
            }
            else{
                break;
            }
        }
        while(start<end){
            ans.push_back(arr[start]);
            start++;
        }
        return ans;
    }
};