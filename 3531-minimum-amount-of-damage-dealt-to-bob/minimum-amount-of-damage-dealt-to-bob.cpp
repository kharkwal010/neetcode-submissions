class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int, int>> terms;
        for(int i=0; i<damage.size(); i++){
            terms.push_back({damage[i], ceil(double(health[i])/power)});
        }
        sort(terms.begin(), terms.end(), [](auto& x, auto& y){
            return (double)x.first/x.second < (double)y.first/y.second;
        });

        for(int i=1; i<terms.size(); i++){
            terms[i].first += terms[i-1].first;
        }
        long long ans = 0;
        for(auto ele: terms){
            // cout<<ele.first<<","<<ele.second<<" ";
            ans += (long long)ele.first * ele.second;
        }
        return ans;
    }
};