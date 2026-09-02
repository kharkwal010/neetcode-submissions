class Solution {
public:
    bool palin(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
      int l=0;
      int r = b.size()-1;
      bool ans = true;
      while(l<r){
            if(a[l]!=b[r]){
                ans = palin(a, l, r) || palin(b, l, r);
                if(ans) return true;
                break;
            }
            l++;
            r--;
      }
      if(ans) return true;
      l = 0;
      r = b.size()-1;
      ans = true;
      while(l<r){
            if(b[l]!=a[r]){
                ans = palin(a, l, r) || palin(b, l, r);
                if(ans) return true;
                break;
            }
            l++;
            r--;
      }
      if(ans) return true;
      return false;

        
    }
};