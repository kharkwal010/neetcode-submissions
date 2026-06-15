class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector <int> front(heights.size(), 0);
        vector <int> back(heights.size(), 0);
        stack<pair<int, int>> values;
        for (int i=0; i<=heights.size(); i++){
            int h;
            if (i<heights.size()){h = heights[i];}
            else {h = 0;}
            while(!values.empty() && values.top().first > h){
                int index = values.top().second;
                values.pop();
                front[index]=i-index;
            }
            values.push({h,i});

        }
        int length =heights.size();
        vector <int> rheights(length);
        for (int i=0; i<length; i++){
            rheights[i]= heights[length - i - 1];
        }

        values = stack<pair<int,int>>();  

         for (int i=0; i<=rheights.size(); i++){
            int h;
            if (i<rheights.size()){h = rheights[i];}
            else {h = 0;}
            while(!values.empty() && values.top().first> h){
                int index = values.top().second;
                values.pop();
                int originalIndex = length - 1 - index;
                back[originalIndex] = i - index;

            }
            values.push({h,i});

        }
        int max_area = 0;

        vector <int> net(length);
        for (int i=0; i<heights.size(); i++){
            net[i]= (front[i]+back[i]-1)* heights[i];
            if (net[i]>max_area){
                max_area = net[i];
            }
        }
        return max_area;



    }
};
