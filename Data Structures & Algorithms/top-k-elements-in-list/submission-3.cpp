class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> number;
        for (int num : nums){
            number[num]++;
        }
        vector<pair<int,int>> arr;
        for (auto& p: number){
            arr.push_back({p.second, p.first});
        }
            sort(arr.rbegin(),arr.rend());
        vector<int> a;
        for (int i=0; i<k; i++){
            a.push_back(arr[i].second);
            
        }
        return a;
    }
};
