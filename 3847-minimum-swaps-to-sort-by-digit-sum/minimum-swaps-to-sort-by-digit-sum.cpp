class Solution {
public:
    int dsum(int n){
        int sum = 0;
        while(n>0){
            int t = n%10;
            n = n/10;
            sum += t;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> index;
        vector<pair<int, int>> terms;
        for(int i=0; i<nums.size(); i++){
            index[nums[i]] = i;
            terms.push_back({dsum(nums[i]), nums[i]});
        }
        sort(terms.begin(), terms.end());
        int swapps = 0;
        for(int i=0; i<nums.size(); i++){
            if(terms[i].second==nums[i]) continue;
            int j = index[terms[i].second];
            index[nums[i]] = j;
            swap(nums[j], nums[i]);
            swapps++;
        }
        return swapps;

    }
};