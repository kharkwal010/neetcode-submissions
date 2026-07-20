class Solution {
public:
    vector<double> nums;
    vector<int> ans;
    Solution(vector<int>& w) {
        ans = w;
        srand(time(0));  // Call once at the start of your program
         int sum = 0;
         double prefix = 0;
         for(int ele: w) sum += ele;
         for(int i=0; i<w.size(); i++){
            double ele = (double)w[i] / sum;
            prefix += ele;
            nums.push_back(prefix);
         }
    }
    
    int pickIndex() {
        int l = 0;
        int r = nums.size()-1;
        if(r==0) return 0;
        double number = (double)rand() / (RAND_MAX+1.0);
        while(l<=r){
            int m = (l + (r - l)/2);
            if(nums[m]>=number) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */