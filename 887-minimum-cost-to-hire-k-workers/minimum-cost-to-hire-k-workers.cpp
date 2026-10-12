class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> terms;
        priority_queue<int> maxheap;

        for(int i=0; i<quality.size(); i++){
            terms.push_back({(double)wage[i]/quality[i], quality[i]});
        }
        sort(terms.rbegin(), terms.rend());
        int n = quality.size();
        int sum = 0;
        for(int i=n-1; i>=(n-k); i--){
            maxheap.push(terms[i].second);
            sum += terms[i].second;
        }

        double ans = sum*(terms[n-k].first);
        for(int i=n-k-1; i>=0; i--){
            sum-=maxheap.top();
            maxheap.pop();
            maxheap.push(terms[i].second);
            sum+=terms[i].second;
            ans = min(ans, terms[i].first*sum);
        }
        return ans;
    }
};