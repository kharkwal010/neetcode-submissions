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

       for(int i=0; i<s.size(); i++){
        int count=0;
        queue.push(s[i]);
        visited.insert(s[i]);
        while(i<s.size() && !queue.empty()){
            original[s[i]-'a']--;
            if(visited.find(s[i])==visited.end()){
                queue.push(s[i]);
                visited.insert(s[i]);
            }
            count++;
            while(original[queue.front()-'a']==0){
                queue.pop();
                if(queue.empty()){
                    break;
                }
            }
            i++;
        }
        i--;
        ans.push_back(count);
       }

    return ans;
    }
};
