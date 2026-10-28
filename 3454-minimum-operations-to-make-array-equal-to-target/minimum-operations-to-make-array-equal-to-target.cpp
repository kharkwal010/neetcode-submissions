class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> terms;
        for(int i=0; i<nums.size(); i++){
            terms.push_back(target[i]-nums[i]);
        }
        long long ans = 0;
        int prev = abs(terms[0]);
        bool pos = true;
        if(terms[0]<0) pos = false;
        // for(int t: terms) cout<<t<<" ";
        for(int i=1; i<terms.size(); i++){
            // cout<<ans<<" ";
            if(pos){
                if(terms[i]<0){
                    pos = !pos;
                    ans += prev;
                    prev = abs(terms[i]);
                    continue;
                }
                else{
                    if(terms[i]>=prev) prev = terms[i];
                    else{
                        ans += prev - terms[i];
                        prev = terms[i];
                    }
                }
            }
            else{
                if(terms[i]>=0){
                    pos = !pos;
                    ans += prev;
                    prev = terms[i];
                    continue;
                }
                else{
                    if(abs(terms[i])<prev){
                        ans += prev - abs(terms[i]);
                    }
                    prev = abs(terms[i]);
                }
            }
            
        }
        ans += prev;
        return ans;
    }
};