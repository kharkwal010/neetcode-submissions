class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<pair<int, string>> words;
        for(string& dict : dictionary){
            words.push_back({dict.size(), dict});
        }
        sort(words.begin(), words.end());
        stringstream ss(sentence);
        string ans;
        string ele;
        while(getline(ss, ele, ' ')){
            int len = ele.size();
            //cout<<ele<<endl;
            for(int i=0; i<words.size(); i++){
                string sub = ele.substr(0, words[i].first);            
                if(sub==words[i].second){
                    // cout<<sub
                    ele = sub;
                    break;
                }
            }           
            ans = ans + ele + " ";
        }
        ans.pop_back();
        return ans;
    }
};