class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          unordered_map<string, vector<string>> grouped;

        for (string s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());  // Use sorted string as key
            grouped[sorted_s].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : grouped) {
            result.push_back(entry.second);
        }

        return result;
   
    }
};
