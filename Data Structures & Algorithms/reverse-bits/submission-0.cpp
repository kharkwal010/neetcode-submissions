class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = bitset<32>(n).to_string();
        int last = s.size()-1;
        string new_s = s;
        for(int i=0; i<=last; i++){
            new_s[i]= s[last-i];
        }
        uint32_t ans = static_cast<uint32_t>(bitset<32>(new_s).to_ulong());
        return ans;
    }
};
