//can do the same question with dfs also but the stucture of dsu is good and it can directly that the components are connected or not, so its better
class DSU{
public:
    int n;
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        this->n = n;
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            this->parent[i] = i;
        }
    }
    int ult_parent(int node){
        if (parent[node]==node) return node;
        return parent[node] = ult_parent(parent[node]);
    }

    bool join(int x, int y){
        int px = ult_parent(x);
        int py = ult_parent(y);
        if(px==py) return false;
        if (size[px] < size[py]) swap(px, py);
        size[px]+=size[py];
        parent[py] = px;
        n--;
        return true;
    }

    bool isConnected(){
        return n==1;
    }

};
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> index;
        DSU find(n);
        for(int i=0; i<nums.size(); i++){
            int f = 2;
            int num = nums[i];
            while(f*f<=num){
                if(num%f==0){
                    if(index.count(f)){
                        find.join(i, index[f]);
                    }
                    else index[f] = i;
                }
                while(num%f==0){
                    num/=f;
                }
                f++;
            }
            if(num>1){
                if(index.count(num)){
                    find.join(i, index[num]);
                }
                else index[num] = i;
            }
        }
        return find.isConnected();
    }
};