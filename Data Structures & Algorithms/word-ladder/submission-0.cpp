class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool present = false;
        for(string words: wordList){
            if(words==endWord){
                present= true;
                break;
            }
        }
        if(!present) return 0;
        int n = beginWord.size();
        unordered_map<string, vector<string>> nei;
        for(string word: wordList){
            for(int j=0; j<n; j++){
                string pattern = word.substr(0,j) + "*" + word.substr(j+1);
                nei[pattern].push_back(word);
            }
        }
        unordered_set<string> visited;
        //bfs:
        queue<pair<int, string>> q;
        q.push({0, beginWord});
        while(!q.empty()){
            string str = q.front().second;
            int trans = q.front().first;
            q.pop();
            if(str==endWord){
                return trans+1;
            }
            visited.insert(str);
            for(int j=0; j<n; j++){
                string pattern = str.substr(0,j) + "*" + str.substr(j+1);
                for(string adj: nei[pattern]){
                    if(visited.find(adj)==visited.end()){
                        q.push({trans+1, adj});
                    }
                }
            }
        }
        return 0;
    }
};
