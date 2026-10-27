class Solution {
public:
unordered_map<string, string> d = {
    {"0", "Zero"},
    {"1", "One"},
    {"2", "Two"},
    {"3", "Three"},
    {"4", "Four"},
    {"5", "Five"},
    {"6", "Six"},
    {"7", "Seven"},
    {"8", "Eight"},
    {"9", "Nine"},
    {"10", "Ten"},
    {"11", "Eleven"},
    {"12", "Twelve"},
    {"13", "Thirteen"},
    {"14", "Fourteen"},
    {"15", "Fifteen"},
    {"16", "Sixteen"},
    {"17", "Seventeen"},
    {"18", "Eighteen"},
    {"19", "Nineteen"},
    {"20", "Twenty"},
    {"30", "Thirty"},
    {"40", "Forty"},
    {"50", "Fifty"},
    {"60", "Sixty"},
    {"70", "Seventy"},
    {"80", "Eighty"},
    {"90", "Ninety"},
    {"100", "Hundred"},
    {"1000", "Thousand"},
    {"1000000", "Million"},
    {"1000000000", "Billion"}
};
    string two_digit(string n){
        if(n=="00") return "";
        if(d.count(n)) return d[n];
        string first = n.substr(1);
        string one = d[first];
        n[1] = '0';
        if(n[0]=='0') return one;
        string two = d[n];
        return (two + " " + one);
    }

    string three_digit(string n){
        string next = n.substr(1);
        if(n[0]=='0') return two_digit(next);
        string last = two_digit(next);
        string first = n.substr(0,1);
        string start = d[first];
        if(last == "") return start + " Hundred";
        return start + " Hundred " + last;
    }

    string numberToWords(int num) {
        
        // cout<<three_digit("000")<<endl;

        string n = to_string(num);
        if(n=="0") return d[n];
        int sz = n.size();
        string ans = "";
        if(sz>9){
            string sub = n.substr(0,1);
            ans = d[sub] +" Billion ";
            n = n.substr(1);
            sz=9;
        }
        
        string zero = string(9-sz, '0');
        n = zero + n;
        string one = n.substr(0,3);
        string two = n.substr(3,3);
        string three = n.substr(6,3);
        string first = three_digit(one);
        if(first!="") ans+= first + " Million ";
        string second = three_digit(two);
        if(second!="") ans+= second + " Thousand ";
        string third = three_digit(three);
        if(third!="") ans += third + " ";
        ans.pop_back();
        return ans;

    }
};