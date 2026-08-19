class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i=0; i<n; i++) q.push(i);
        int j = 0;
        bool pick = false;
        while(!q.empty()){
            pick = !pick;
            int curr = q.front();
            q.pop();
            if(pick){
                ans[curr] = deck[j];
                j++;
            }
            else{
                q.push(curr);
            }
        }
        return ans;
    }
};