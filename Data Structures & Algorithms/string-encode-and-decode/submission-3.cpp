class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        
        for(auto str : strs){
            int length = str.size();
            s= s+ to_string(length)+ "#" + str;
        
        }
        return s;
        
    }

    vector<string> decode(string s) {
        vector <string> str;
        int n = s.size();
        for(int i=0; i<n; i++){
            int j=i;
            while(s[j]!='#'){
                j++;
                

            }
            int length= stoi(s.substr(i, j-i));
            i = 1+j;
            j = i +length;
            str.push_back(s.substr(i, length));
            i=j-1;



    }
    return str;
    }
};

