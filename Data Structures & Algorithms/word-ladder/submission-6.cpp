class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       wordList.push_back(beginWord);
       unordered_map<string, vector<string>> match;
       bool present = false;
       for(string s: wordList){
            if(s==endWord) present = true;
       }
       int n = beginWord.size();
       if(!present) return 0; 
       for(string word: wordList){
        for(int i=0; i<word.size(); i++){
            string key = word.substr(0, i) + "*" + word.substr(i+1, n-i-1);
            match[key].push_back(word);
        }
       }
       unordered_set<string> visited;
       visited.insert(beginWord);
       int count=1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                string st = q.front();
                q.pop();
                for(int i=0; i<st.size(); i++){
                    string k = st.substr(0, i) + "*" + st.substr(i+1, n-i-1);
                    for(auto ele: match[k]){
                        if(visited.count(ele)) continue;
                        if(ele==endWord) return count+1;
                        visited.insert(ele);
                        q.push(ele);
                    }
                }
            }
            count++;
        }
        return 0;    
       

    }
};
