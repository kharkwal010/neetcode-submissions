class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> one;
        unordered_map<int, int> two;
        int mini = INT_MAX;
        for(int b: basket1){
            one[b]++;
            mini = min(mini, b);
        }
        for(int b: basket2){
            two[b]++;
            mini = min(mini, b);
        }
        priority_queue<int> maxheap;
        vector<int> second;
        for(auto& ele: one){
            int b = ele.first;
            int m = one[b];
            int n = two[b];
            if((m+n)%2==1) return -1;
            // cout<<b<<" "<<m<<" "<<n<<endl;
            if(m>n){
                for(int i=0; i<(m-n)/2; i++) second.push_back(b);
            }
        }

        for(auto& ele: two){
            int b = ele.first;
            int m = one[b];
            int n = two[b];
            if((m+n)%2==1) return -1;
            if(m<n){
                for(int i=0; i<(n-m)/2; i++) maxheap.push(b);
            }            
        }
        long long ans = 0;
        sort(second.rbegin(), second.rend());
        while(!maxheap.empty()){
            int a = maxheap.top();
            maxheap.pop();
            long long s1 = min(a, second.back());
            long long s2  = 2*mini;
            if(s1<s2){
                ans += s1;
                second.pop_back();
            }
            else{
                ans += s2;                
            }
        }
        return ans;
    }
};