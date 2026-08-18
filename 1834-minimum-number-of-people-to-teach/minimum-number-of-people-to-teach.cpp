class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<unordered_set<int>> langs(n+1);
        for(int i=0; i<languages.size(); i++){
            for(int ele: languages[i]){
                langs[ele].insert(i+1);
            }
        }
        unordered_set<int> people;
        for(auto ele: friendships){
            int one = ele[0];
            int two = ele[1];
            bool present = false;
            for(int l: languages[one-1]){
                if(langs[l].count(two)){
                    present = true;
                    break;
                }
            }
            if(!present){
                people.insert(one);
                people.insert(two);
            }
        }
        vector<int> bhasha(n+1, 0);
        for(int ele: people){
            for(int l: languages[ele-1]){
                bhasha[l]++;
            }
        }
        int maxi = *max_element(bhasha.begin(), bhasha.end());
        return people.size() - maxi;
        
    }
};