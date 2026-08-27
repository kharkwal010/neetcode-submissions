class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> points;
        for(string& w: words) points[w]++;
        int number = words.size();
        vector<int> ans;

        int n = words[0].size();
        for(int i=0; i<n; i++){
            vector<string> terms;
            for(int j=i; j+n<=s.size(); j+=n){
                terms.push_back(s.substr(j, n));
                // cout<<s.substr(j, n)<<" ";
            }
            // cout<<endl;

            int l = 0;
            int count = 0;
            int r = 0;
            
            while(r<terms.size()){
                if(!points.count(terms[r])){
                    while(l<r){
                        points[terms[l]]++;
                        l++;
                    }
                    count = 0;
                    r++;
                    l++;
                }
                else{
                    while(points[terms[r]]==0){
                        points[terms[l]]++;
                        l++;
                        count--;
                    }  
                    points[terms[r]]--;
                    count++;
                    if(count==number){
                        ans.push_back(i+n*l);
                        points[terms[l]]++;
                        count--;
                        l++;
                    }
                    r++;
                }
            }
            while(l<r){
                points[terms[l]]++;
                l++;
            }
        }
        return ans;
    }
};