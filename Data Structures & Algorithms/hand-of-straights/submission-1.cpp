class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0){
            return false;
        }
        map<int, int> numbers;
        for(int i: hand){
            numbers[i]++;
        }
        priority_queue <int , vector<int>, greater<int>> queue;
        for(auto& num : numbers){
            queue.push(num.first);
        }
        while(queue.size()!=0){
            int first = queue.top();
            for(int i=0; i<groupSize; i++){
                if(numbers[first+i]){
                numbers[first+i]--;
                }
                else{
                    return false;
                }
                if(numbers[first+i]<0){
                    return false;
                }
                if(numbers[first+i]==0){
                    queue.pop();
                }
            }
        }
        return true;
        

    }
};
