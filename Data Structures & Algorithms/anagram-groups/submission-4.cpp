class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string , vector<string>> groups;
        for(string words: strs){
            string unsorted_word = words;
            sort(words.begin(), words.end());
            groups[words].push_back(unsorted_word);
        }
        vector<vector<string>> ans;
        
        for(auto ele: groups){
            ans.push_back(ele.second);
        }
        return ans;
        
    }

};
