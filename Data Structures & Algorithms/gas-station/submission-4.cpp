class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> rem(gas.size());
        for(int i=0; i<gas.size(); i++){
            rem[i] = gas[i]-cost[i];
        }
        int total = accumulate(rem.begin(), rem.end(), 0);
        if(total<0){
            return -1;
        }
        int start = 0;
        int sum = 0;
        for(int i=0; i<rem.size(); i++){
            sum = sum+rem[i];
            if(sum<0){
                sum = 0;
                start = i+1;
            }
        }
        return start;

    }
};
