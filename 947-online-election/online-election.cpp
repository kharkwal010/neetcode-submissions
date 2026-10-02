class TopVotedCandidate {
public:
    vector<int> winner;
    vector<int> time;
    vector<int> voted;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> freq;
        int m_freq = 1;
        int win = 0;
        for(int i=0; i<persons.size(); i++){
            int p = persons[i];
            time.push_back(times[i]);
            voted.push_back(p);

            freq[p]++;
            if(freq[p]>=m_freq){
                win = p;
                m_freq = freq[p];
            }
            winner.push_back(win);
        }
    }

    int lower(vector<int>& times, int t){
        int l = 0;
        int r = times.size()-1;
        int ans = r;
        while(l<=r){
            int m = (l + r) / 2;
            if(times[m]<=t){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
    
    int q(int t) {
        int find = lower(time, t);
        // cout<<find<<endl;
        return winner[find];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */