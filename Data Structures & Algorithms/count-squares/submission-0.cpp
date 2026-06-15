class CountSquares {
public:
    unordered_map<int, vector<int>> rowpair;
    unordered_map<string, int> counts;
    CountSquares() {        
    }
    
    void add(vector<int> point) {
        int row = point[0];
        int column = point[1];
        string key = to_string(row)+"+"+to_string(column);
        if(counts.find(key)==counts.end()){
            rowpair[row].push_back(column); 
        }
        counts[key]++;
        return;

    }
    
    int count(vector<int> point) {
        int r = point[0];
        int c = point[1];
        int number = 0;
        for(int col: rowpair[r]){
            int diff = col - c;
            if(diff!=0){
                    string key1 = to_string(r+diff)+"+"+to_string(c);
                    string key2 = to_string(r+diff)+"+"+to_string(c+diff);
                    string key3 = to_string(r)+"+"+to_string(c+diff);

                    string key4 = to_string(r-diff)+"+"+to_string(c+diff);
                    string key5 = to_string(r-diff)+"+"+to_string(c);
                    string key6 = to_string(r)+"+"+to_string(c+diff);

                    int one = counts[key1];
                    int two = counts[key2];
                    int three = counts[key3];
                    int four = counts[key4];
                    int five = counts[key5];
                    int six = counts[key6];
                    number = number + one*two*three;   
                    number = number + six*four*five;               
            
            }
        }
        return number;
    }
};
