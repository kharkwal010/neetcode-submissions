class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int p){
        if(parent[p]==p) return p;
        return parent[p] = find(parent[p]);
    }

    bool merge(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return false;
        if(size[pa]>size[pb]){
            size[pa] += size[pb];
            parent[pb] = pa;
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }
        return true;
    }
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        for(auto s: swaps){
            merge(s[0], s[1]);
        }
        unordered_map<int, vector<int>> terms;
        for(int i=0; i<n; i++){
            int p = find(i);
            terms[p].push_back(i);
        }
        long long sum = 0;
        for(auto& ele: terms){
            vector<int> val;
            int odd = 0;
            for(int e: ele.second){
                if(e%2==1) odd++;
                val.push_back(nums[e]);
            }

            sort(val.begin(), val.end());
            long long oddsum = 0;
            long long evensum = 0;
            for(int i=0; i<odd; i++) oddsum += val[i];
            for(int i=odd; i<val.size(); i++) evensum += val[i];
            sum += evensum - oddsum;
        }
        return sum;
    }
};