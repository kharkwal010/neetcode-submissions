class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
       priority_queue<int> low;
       priority_queue<int, vector<int>, greater<int>> high;
       unordered_map<int, int> removed;
       for(int i=0; i<k; i++){
            low.push(nums[i]);
       }
       for(int i=0; i<k/2; i++){
            high.push(low.top());
            low.pop();
       }

       vector<double> ans;
       if(k%2!=0) ans.push_back(low.top());
       else ans.push_back((1.0*low.top() + 1.0*high.top())/2);

       for(int i=k; i<nums.size(); i++){
            removed[nums[i-k]]++;
            if(low.top()>=nums[i-k]) low.push(nums[i]);
            else high.push(nums[i]);

            if(!high.empty() && low.top()>high.top()){
                int l = low.top();
                low.pop();
                low.push(high.top());
                high.pop();
                high.push(l);
            }

            while(removed.count(low.top())){
                int c = low.top();
                low.pop();
                removed[c]--;
                if(removed[c]==0) removed.erase(c);
            }

            while(!high.empty() && removed.count(high.top())){
                int c = high.top();
                high.pop();
                removed[c]--;
                if(removed[c]==0) removed.erase(c);
            }

            

            if(k%2!=0) ans.push_back(low.top());
            else ans.push_back((1.0*low.top() + 1.0*high.top())/2);

       }
       return ans;
    }
};





















/*
simple observations that i made while doing this questions:
    1. in case of ideal situations there should be same number of elements in both low and high heap.
    2. so we just need to know from where the earlier element will leave, so that we can insert the new element on that side of heaps.
    3. if the element is on the top we can simply remove or pop them out and it was obvious that we can make deletion after adding and adjusting the heaps as we already knew in which heap we need to insert the element.
*/