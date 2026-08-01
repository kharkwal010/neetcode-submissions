class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> count;
        unordered_map<int, int> res;
        for(int& p: planks){
            count[p]++;
            res[p]++;
        }
        vector<int> ele;
        for(auto& e : count){
            ele.push_back(e.first);
        }
        int n = ele.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int term = ele[i] + ele[j];
                if(i==j){
                    res[term] += count[ele[i]]/2;
                }
                else res[term] += min(count[ele[i]], count[ele[j]]);
            }
        }
        int ans = 0;
        for(auto& e: res){
            ans = max(ans, e.second);
        }
        return ans;
    }
};