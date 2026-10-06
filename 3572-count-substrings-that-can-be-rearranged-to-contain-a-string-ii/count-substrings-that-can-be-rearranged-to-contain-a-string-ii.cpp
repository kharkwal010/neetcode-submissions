class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int r = 0;
        int l = 0;
        vector<int> search(26,0);
        int count = 0;
        for(char c: word2){
            search[c-'a']++;
        }
        for(int i: search) if(i>0) count++;
        int found = 0;
        vector<int> take(26,0);

        long long ans = 0;
        int n = word1.size();
        while(r<=word1.size()){
            if(found==count){
                ans += n - r + 1;
                int j = word1[l]-'a';
                if(take[j]==search[j]) found--;
                take[j]--;
                l++;  
                continue;              
            }
            if(r==word1.size()) break;
            int k = word1[r]-'a';
            take[k]++;
            if(take[k]==search[k]){
                found++;
            }
            r++;
            // cout<<found<<" "<<count<<endl;
        }
        return ans;

    }
};