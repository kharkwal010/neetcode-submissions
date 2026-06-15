/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int l = 0;
        int r = len-1;
        int p = 0;
        while(l<=r){
            int m = (l+r)/2;
            int prev = mountainArr.get(m-1);
            int curr = mountainArr.get(m);
            int next = mountainArr.get(m+1);
            if(curr>prev && curr>next){
                p = m;
                break;
            }
            else if(prev<curr && curr<next) l = m+1;
            else r = m-1;
        }

        l = 0;
        r = p;
        int left = mountainArr.get(l);
        int right = mountainArr.get(r);
        if(target>=left && target<=right){
            while(l<=r){
                int m = (l+r)/2;
                int curr = mountainArr.get(m);
                if(curr==target) return m;
                else if(curr<target) l = m + 1;
                else r = m-1;
            }

        }

        l = p+1;
        r = len-1;
        left = mountainArr.get(l);
        right = mountainArr.get(r);
        if(target<=left && target>=right){
            while(l<=r){
                int m = (l+r)/2;
                int curr = mountainArr.get(m);
                if(curr==target) return m;
                else if(curr<target) r = m - 1 ;
                else l = m+1;
            }

        }
        return -1;
        
       
        
    }
};