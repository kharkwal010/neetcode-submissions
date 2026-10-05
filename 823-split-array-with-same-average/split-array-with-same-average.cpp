class Solution {
public:    
    void comb(vector<int>& nums, int& end, int sum, int i, int count, vector<unordered_set<int>>& val){
        if(i==end){
            val[count].insert(sum);
            return;
        }
        comb(nums, end, sum + nums[i], i+1, count+1, val);
        comb(nums, end, sum, i+1, count, val);
        return;
    }

    bool splitArraySameAverage(vector<int>& nums) {
       int n1 = nums.size()/2;
       int n2 = nums.size() - n1;
        vector<unordered_set<int>> left(n1+1);
        vector<unordered_set<int>> right(n2+1);
        int n = nums.size();
       
       comb(nums, n1, 0, 0, 0, left);
       comb(nums, n, 0, n1, 0, right);
       int total = accumulate(nums.begin(), nums.end(), 0);

       for(int i=0; i<left.size(); i++){
            for(int s1: left[i]){
                for(int j=0; j<right.size(); j++){
                    int t = i+j;
                    if(t==0 || t==n) continue;
                    if((total * t) % n!=0) continue;
                    int search = (total * t) / n - s1;
                    if(right[j].count(search)) return true;
                }
            }
       }
       return false; 
    }
};