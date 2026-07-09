class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long d = abs((long long)denominator);
        long long s = 1LL* numerator * denominator;
        string sign;
        if(s<0) sign = "-";
        long long n = abs((long long)numerator/ (long long)denominator);
        string ans = sign + to_string(n);
        if(numerator%d==0) return ans;
        long long num = abs(numerator % d);
        ans.push_back('.');
        unordered_map<long long, int> index;
        string two;
        int i=0;
        while(num!=0){
            num = 10*num;
            int rem = num%d;
            if(index.count(num)){
                two.push_back(')');
                int j = index[num];
                two.insert(two.begin()+j, '(');
                break;
            }
            two.push_back(num/d+'0');
            index[num] = i;
            num = rem;
            i++;
        }
        return ans + two;

    }
};