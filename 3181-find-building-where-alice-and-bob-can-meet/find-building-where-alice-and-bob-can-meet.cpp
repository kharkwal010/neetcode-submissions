class Solution {
public:
    vector<int> segment;
    int build(vector<int>& heights, int l, int r, int i){
        if(l==r) return segment[i] = l;
        int m = (l+r)/2;
        int left = build(heights, l, m, 2*i+1);
        int right = build(heights, m+1, r, 2*i+2);
        int res = 0;
        if(heights[left]>=heights[right]){
            res = left;
            segment[i] = left;
        }
        else{
            res = right;
            segment[i] = res;
        }
        return res;    
    }

    int query(vector<int>& heights, int& left, int& right, int l, int r, int i){
        if(left>r || right<l) return -1;
        if(left<=l && right>=r) return segment[i];
        int m = (l+r)/2;
        int lregion = query(heights, left, right, l, m, 2*i+1);
        int rregion = query(heights, left, right, m+1, r, 2*i+2);
        if(lregion==-1) return rregion;
        else if(rregion==-1) return lregion;
        if(heights[lregion]>=heights[rregion]) return lregion;
        return rregion;
    }


    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segment.resize(4*n);
        build(heights, 0, heights.size()-1, 0);
        vector<int> ans;
        for(auto& q: queries){
            int l = q[0];
            int r = q[1];            
            if(l>r) swap(l, r);

            if(l==r) ans.push_back(l);
            else if(heights[r]>heights[l]) ans.push_back(r);            
            else{
                int max_height = heights[l];
                l = r+1;
                r = heights.size()-1;
                int res = -1;
                while(l<=r){
                    int m = (l+r) / 2;
                    int curr = query(heights, l, m, 0, n-1, 0);
                    if(curr!=-1 && heights[curr]>max_height){
                        res = curr;
                        r = m-1;
                    }
                    else l = m + 1;
                }
                ans.push_back(res);
            } 
            
        }
        return ans;
    }
};