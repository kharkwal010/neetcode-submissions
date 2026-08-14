class Solution {
public:
    int minimumPartition(string s, int k) {
        vector<bool> terms(10, false);
        int l = 0;
        int count = 1;
        for(int i=0; i<s.size(); i++){
            long long curr = stoll(s.substr(l,i-l+1));
            if(s[i]-'0'>k) return -1;
            if(curr>k){
                count ++;
                l=i;
                for(int i=0; i<10; i++) terms[i] = false;
            }
            terms[s[i]-'0'] = true;
        }
        return count;
    }
};