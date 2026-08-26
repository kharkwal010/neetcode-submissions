class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long len = 1;
        int i = -1;
        while(len<k){
            len*=2;
            i++;
        }
        int shift = 0;
        k = k-1;
        while(i>=0){
            long long half = len/2;
            len = len/2;
            // cout<<i<<" "<<operations[i]<<endl;
            if(k>=half){
                shift += operations[i];
                k = k - len;
            }            
            i--;
        }
        return 'a' + shift % 26;

    }
};