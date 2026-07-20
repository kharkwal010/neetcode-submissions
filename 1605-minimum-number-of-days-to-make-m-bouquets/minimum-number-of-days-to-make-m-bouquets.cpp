class Solution {
public:
    int check(vector<int>& day, int& m, int& k, int val){
        int count = 0;
        int curr = 0;
        for(int i=0; i<day.size(); i++){
            if(day[i]<=val){
                curr++;
            }
            else curr=0;
            if(curr==k){
                curr=0;
                count++;
            }
        }
        if(count>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if((long long)m*k>n) return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while(l<r){
            int mid = (l + (r - l)/2);
            if(check(bloomDay, m, k, mid)) r = mid;
            else l = mid+1;
        }
        return l;
    }
};