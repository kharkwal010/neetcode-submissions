class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> original(26,0);
        for(int i=0; i<s.size(); i++){
            original[s[i]-'a']++;
        }
        queue<char> queue;
        vector<int> ans;
        unordered_set<char> visited;

        for(int i=0; i<s.size();i++){
            int counter=0;
            bool allow = true;

            while(!queue.empty() || allow){
                if(visited.find(s[i])==visited.end()){
                    queue.push(s[i]);
                    allow = false;
                    visited.insert(s[i]);
                }
                counter++;
                original[s[i]-'a']--;
                while(original[queue.front()-'a']==0){
                    queue.pop();
                    if(queue.empty()){
                        break;
                    }
                }
                i++;
            }
                i--;
            ans.push_back(counter);


        }
        return ans;

    }
};
