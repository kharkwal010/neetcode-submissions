class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for(int n: nums){
            int term = n%value;
            if(term<0) term+=value;
            freq[term]++;
        }
        int curr = 0;
        while(true){
            if(freq[curr%value]==0) return curr;
            freq[curr%value]--;
            curr++;
        }
        
    }
};