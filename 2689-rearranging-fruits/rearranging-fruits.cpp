class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
       unordered_map<int, int> one;
       unordered_map<int, int> two;
       unordered_set<int> elements;
       int mini = INT_MAX;
       for(int b: basket1){
         one[b]++;
         elements.insert(b);
         mini = min(mini, b);
       }
       for(int b: basket2){
        two[b]++;
        elements.insert(b);
        mini = min(mini, b);
       }
       vector<int> top;
       vector<int> bottom;

       for(int ele: elements){
        int cnt = one[ele];
        int scnt = two[ele];
        if((cnt+scnt)%2==1) return -1;
        if(cnt==scnt) continue;
        while(cnt>scnt){
            top.push_back(ele);
            cnt--;
            scnt++;
        }
        while(cnt<scnt){
            bottom.push_back(ele);
            cnt++;
            scnt--;
        }
       }
       long long ans =0;
       sort(top.begin(), top.end());
       sort(bottom.rbegin(), bottom.rend());
       
       for(int i=0; i<top.size(); i++){
        long long curr = min(top[i], bottom[i]);
        if(2LL*mini<curr) curr = 2*mini;
        ans += curr;
       } 
       return ans;
    }
};