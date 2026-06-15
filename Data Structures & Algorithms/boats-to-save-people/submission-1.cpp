class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int start = 0;
        int end = people.size()-1;
        int count = 0;
        sort(people.begin(), people.end());

        while(start<=end){
            if(people[start]+people[end]<=limit){
                start++;
            }
            end--;
            count++;
        }
        return count;
    }
};