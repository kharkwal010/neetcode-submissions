class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> nums;
    int small(vector<int>& terms, int left){
        int l = 0;
        int r = terms.size()-1;
        if(terms[r]<left) return r+1;
        int ans = r;
        while(l<=r){
            int m = (l+r)/2;
            if(terms[m]<left){
                l = m+1;
            }
            else{
                ans = m;
                r = m-1;
            }
        }
        return ans;
    }

    int large(vector<int>& terms, int right){
        int l = 0;
        int r = terms.size()-1;
        if(terms[l]>right) return -1;
        int ans = l;
        while(l<=r){
            int m = (l+r)/2;
            if(terms[m]<=right){
                ans = m;
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return ans;
    }
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0; i<arr.size(); i++){
            nums[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        // if(value==33){
        //     for(int ele: terms) cout<<ele<<" ";
        //     cout<<endl;
        // }
        if(nums[value].empty()) return 0;
        int l = small(nums[value], left);
        int r = large(nums[value], right);
        // cout<<value<<" "<<l<<" "<<r<<endl;
        return max(0, r-l+1);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */