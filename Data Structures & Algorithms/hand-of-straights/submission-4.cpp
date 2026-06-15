class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> numbers;
        if(hand.size()%groupSize!=0){
            return false;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        for(int i=0; i<hand.size(); i++){
            numbers[hand[i]]++;
        }
        for(auto num: numbers){
            minheap.push({num.first,num.second});
        }
        while(!minheap.empty()){
            vector<vector<int>> layer;
            int prev = -1;

            for(int i=0; i<groupSize; i++){
                auto top = minheap.top();                                
                if(prev!=-1 && top[0]-prev!=1){
                    return false;
                }
                minheap.pop();
                layer.push_back(top);
                prev = top[0];          
                 
            }
            for(auto terms: layer){
                if(terms[1]>1){
                    minheap.push({terms[0], terms[1]-1});
                }
            }

        }
        return true;
        

    }
};
