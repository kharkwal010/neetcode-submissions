class Solution {
public:
    bool check(vector<int>& positions, int m, int val){
        int next = positions[0] + val;
        m--;
        int i = 1;
        bool present = false;
        // cout<<"val: "<<val<<endl;
        while(i<positions.size()){
            if(positions[i]<next){
                present = true;
                i++;
            }
            else{
                next = positions[i] + val;
                i++;
                m--;
            }
            // cout<<m<<endl;
            if(m==0) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0;
        int maxi = *max_element(position.begin(), position.end());
        int mini = *min_element(position.begin(), position.end());
        int r = 1e9;
        while(l<=r){
            int mid = (l + (r - l) / 2);
            if(check(position, m, mid)) l = mid + 1;
            else r = mid -1;
        }
        return l-1;
    }
};