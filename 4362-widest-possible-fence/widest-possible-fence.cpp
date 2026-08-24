class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> height;
        vector<pair<int, int>> terms;
        int ans = 0;
        for(int p: planks){
            height[p]++;
            ans = max(ans, height[p]);
        }
        for(auto& ele: height){
            terms.push_back({ele.first, ele.second});
        }
        for(int i=0; i<terms.size(); i++){
            for(int j=i; j<terms.size(); j++){
                int h = terms[i].first + terms[j].first;
                int c = min(terms[i].second, terms[j].second);
                if(i==j) c = c/2;
                height[h] += c;
                ans = max(height[h], ans);
            }
        }  
        return ans;      
    }
};