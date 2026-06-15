class Solution {
public:
    bool checkValidString(string s) {
      int minopen = 0;
      int maxopen = 0;
      for(char br: s){
        if(br==')'){
            minopen--;
            maxopen--;
        }
        else if(br=='('){
            minopen++;
            maxopen++;
        }
        else if(br=='*'){
            minopen--;
            maxopen++;
        }
        if(minopen<0){
            minopen = 0;
        }
        if(maxopen<0){
            return false;
        }
      }
      if(minopen>0){
        return false;
      }
      return true;
    }
};
