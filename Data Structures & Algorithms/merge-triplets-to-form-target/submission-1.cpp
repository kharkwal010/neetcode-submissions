class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool flag1, flag2, flag3 = false;
        for(auto& t: triplets){
            if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2]){
                continue;
            }
            if(t[0]==target[0]){
                flag1 = true;
            }
             if(t[1]==target[1]){
                flag2 = true;
            }
             if(t[2]==target[2]){
                flag3 = true;
            }
            

        }
        if(flag1 && flag2 && flag3){
            return true;

        }
        return false;
        
    }
};
