class Solution {
public:
    int hammingWeight(uint32_t n) {
        string s = bitset<32>(n).to_string();
        int count =0;
        for (char let : s){
            if (let == '1'){
                count++;
            }
        }
        return count;
    }
};
