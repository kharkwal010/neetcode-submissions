class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> right(arr.size());
        int mini = INT_MAX;
        for(int i=arr.size()-1; i>=0; i--){
            mini = min(arr[i], mini);
            right[i] = mini;
        }
        int chunk = 1;
        int curr = -1;
        for(int i=0; i<arr.size()-1; i++){
            curr = max(curr, arr[i]);
            // cout<<curr<<" "<<right[i]<<endl;
            if(right[i+1]>=curr) chunk++;            
        }
        return chunk;
    }
};