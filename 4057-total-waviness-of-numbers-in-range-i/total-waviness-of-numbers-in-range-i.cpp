class Solution {
public:
   
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i=num1; i<=num2; i++){
            vector<int> terms;
            int curr = i;
            while(curr>0){
                terms.push_back(curr%10);
                curr = curr/10;
            }
            for(int i=1; i<terms.size()-1; i++){
                if(terms[i]>terms[i-1] && terms[i]>terms[i+1]) count++;
                else if(terms[i]<terms[i-1] && terms[i]<terms[i+1]) count++;
            }
        }
        return count;
    }
};