class Solution {
public:
    long long countOfSubstrings(string word, int k) {
       int count = 0;
       unordered_map<char, int> ch;
       unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
       int cons = 0;
       long long ans = 0;
       int i_far = 0;
       int i_near = 0;

       for(int i=0; i<word.size(); i++){
            if(vowel.count(word[i])){
                if(ch[word[i]]==0) count++;
                ch[word[i]]++;
            }
            else{
                cons++;
                if(cons>k){
                    while(vowel.count(word[i_near])){
                        ch[word[i_near]]--;
                        if(ch[word[i_near]]==0) count--;
                        i_near++;
                    }
                    cons--;
                    i_near++;
                    i_far = i_near;
                }
            }
            while(ch[word[i_near]]>1){
                ch[word[i_near]]--;
                i_near++;
            }
            if(count==5 && cons==k){
                ans += i_near - i_far + 1;
            }
       }
        return ans;


    }
};