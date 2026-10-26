class Solution {
public:
    int countMagicalPairs(string s) {
        int ans = 0;
        for(int i=0; i<s.size()-1; i++){
            vector<int> left(27,0);
            vector<bool> leftc(26, true);
            int dis = 0;
            for(int j=i; j>=0; j--){
                dis = dis + leftc[s[j]-'a'];
                leftc[s[j]-'a'] = false;
                left[dis]++;
            }

            vector<int> right(27,0);
            vector<bool> rightc(26,true);
            dis = 0;
            for(int k=i+1; k<s.size(); k++){
                dis += rightc[s[k]-'a'];
                rightc[s[k]-'a'] = false;
                right[dis]++;
            }

            for(int i=1; i<27; i++){
                if(left[i]==0 || right[i]==0) break;
                ans += left[i] * right[i];
            }          

        }
        return ans;
    }
};