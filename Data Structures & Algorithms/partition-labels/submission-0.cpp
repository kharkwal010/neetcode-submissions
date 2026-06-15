class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> letters;
        for (int i=0; i<s.size(); i++){
            letters[s[i]]++;
        }
        int start = 0;
        unordered_set<char> elements;
        queue<char> queue;
        vector <int> res;
        for (int i=0; i<s.size(); i++){
            if (letters[s[i]]>0){
                letters[s[i]]--;
                if (elements.find(s[i])==elements.end()){
                    queue.push(s[i]);
                }
                elements.insert(s[i]);
            }
            if (letters[s[i]]==0 && s[i]==queue.front()){
                
                while(queue.size()>0 && letters[queue.front()]==0){                    
                    queue.pop();
                }
                if(queue.size()==0){
                    res.push_back(i-start+1);
                    start = i+1;

                }
            }
        }
        return res;
    }
};
