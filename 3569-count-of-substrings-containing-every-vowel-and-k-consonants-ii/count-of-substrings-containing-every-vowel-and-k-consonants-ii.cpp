class Solution {
public:
    long long counting(string& word, int k){
        int cons = 0;
        int count = 0;
        long long ans = 0;
        int n = word.size();
        unordered_map<char, int> freq;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int l = 0;
        int r = 0;
        while(r<word.size()){
            if(vowels.count(word[r])){
                if(freq[word[r]]==0) count++;
                freq[word[r]]++;
            }
            else cons++;
            while(count==5 && cons>=k){
                ans += n - r;
                if(vowels.count(word[l])){
                    freq[word[l]]--;
                    if(freq[word[l]]==0) count--;
                }
                else cons--;
                l++;                
            }
            r++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        // cout<<counting(word, k)<<" "<<counting(word, k+1)<<endl;
        return counting(word, k) - counting(word, k+1);
    }
};