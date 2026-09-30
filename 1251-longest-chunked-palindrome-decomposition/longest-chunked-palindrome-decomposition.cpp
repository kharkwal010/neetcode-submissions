class Solution {
public:
    bool check(string& text, int l, int r, int lend, int rend){
        while(l<=lend && r<=rend){
            if(text[l]!=text[r]) return false;
            l++;
            r++;
        }
        return true;
    }
    int longestDecomposition(string text) {
        int l = 0;
        int r = text.size()-1;
        int count = 0;

        while(l<=r){
            for(int i=l; i<=r; i++){
                if(i==r) return count+1;
                if(text[i]==text[r]){
                    int j = i - l;
                    if(check(text, l, r-j, i, r)){
                        count+=2;
                        l = i+1;
                        r = r-j-1;
                        break;
                    }
                }

            }
        }
        return count;
    }
};