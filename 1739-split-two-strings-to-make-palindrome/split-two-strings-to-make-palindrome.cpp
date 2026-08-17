class Solution {
public:
    bool check(string& a, string& b, bool swapping, int i, int j){        
        while(i<j){
            if(a[i]==b[j]){
                i++;
                j--;
            }
            else{
                if(swapping){
                    bool swapping = false;
                    return check(a, a, swapping, i, j) || check(b, b, swapping, i, j);                 
                }
                return false;
            }
        }
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
        int l = 0;
        int r = a.size()-1;
        if(check(a, b, true, l, r ) || check(b, a, true, l, r)) return true;
        return false;
        
        
    }
};