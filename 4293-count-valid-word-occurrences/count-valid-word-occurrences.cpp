class Solution {
public:
    unordered_map<string, int> terms;
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string overall = "";
        for(string& s: chunks){
            overall+=s;
        }
        int n = overall.size();

        int l = 0;
        unordered_set<char> ch = {' ', '-'};
        for(int i=0; i<overall.size(); i++){
            if(overall[i]==' ' || overall[i]=='-' && (i==0 || i==n-1 || ch.count(overall[i-1]) || ch.count(overall[i+1]))){
                if(l==i){
                    l++;
                }
                else{
                    string term = overall.substr(l, i-l);
                    terms[term]++;
                    l = i+1;
                }
                continue;
            }
        }
        if(l!=n){
            string term = overall.substr(l);
            terms[term]++;
        }

        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            ans[i] = terms[queries[i]];
        }
        return ans;
    }
};