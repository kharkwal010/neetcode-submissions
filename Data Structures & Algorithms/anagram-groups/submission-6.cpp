class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string , vector<string>> groups;
       
        for(string words: strs){
            string key = "";
            vector<int> count(26,0);
            for(char ch: words){
                count[ch-'a']++;
            }
            for(int i=0; i<26; i++){
                key = key + ","+ to_string(count[i]);
            }
            groups[key].push_back(words);            
        }
        vector<vector<string>> ans;
        
        for(auto ele: groups){
            ans.push_back(ele.second);
        }
        return ans;
        
    }

};


/*
in unordered_maps----> element.push_back();
we can also make maps like---> unodered_map<string, vector<string>> name;
sort(element.begin(), element.end());
if you want to search an element in a array in o(1)--->make set of that particular array;
*/


