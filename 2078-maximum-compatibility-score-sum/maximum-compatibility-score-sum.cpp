class Solution {
public:
    int compat(vector<int>& one, vector<int>& two){
        int count = 0;
        for(int i=0; i<one.size(); i++){
            if(one[i]==two[i]) count++;
        }
        return count;
    }

    int maxcompat(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, vector<bool>& visited){
        if(i==students.size()) return 0;
        int ans = 0;
        for(int j=0; j<mentors.size(); j++){
            if(!visited[j]){
                visited[j] = true;
                ans = max(ans, compat(students[i], mentors[j]) + maxcompat(students, mentors, i+1, visited));
                visited[j] = false;
            }
        }
        return ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        vector<bool> visited(n, false);
        return maxcompat(students, mentors, 0, visited);
    }
};