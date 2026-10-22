class NumArray {
public:
    vector<int> seg;
    int n;
    int build(vector<int>&nums, int i, int l, int r){
        if(l==r) return seg[i] = nums[l];
        int m = l + (r - l)/2;
        int left = build(nums, 2*i+1, l, m);
        int right = build(nums, 2*i+2, m+1, r); 
        return seg[i] = left + right;
    }

    void change(int index, int val, int l, int r, int i){
        if(l==r){
            seg[i] = val;
            return;
        }
        int m = l + (r - l)/2;
        if(index<=m) change(index, val, l, m, 2*i+1);
        else change(index, val, m+1, r, 2*i+2);
        seg[i] = seg[2*i+1] + seg[2*i+2];    
    }

    int query(int& left, int& right, int i, int l, int r){
        if(right<l || left>r) return 0;
        if(left<=l && right>=r) return seg[i];
        int m = l + (r - l) / 2;
        return query(left, right, 2*i+1, l, m) + query(left, right, 2*i+2, m+1, r);
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(nums, 0, 0, n-1);
    }
    
    void update(int index, int val) {
        // cout<<seg[0]<<endl;
        change(index, val, 0, n-1, 0);
        // cout<<seg[0]<<endl;
    }
    
    int sumRange(int left, int right) {
        return query(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */