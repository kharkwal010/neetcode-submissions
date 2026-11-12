class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       map<tuple<int, int, int>, int> mp;
        int n = points.size();
        if(n<=2) return n;
        int m = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int a = (y2 - y1);
                int b = (x1 - x2);
                int c = -1 * (a*x1 + b*y1);

                int g = gcd(a, gcd(b, c));
                
                a = a/g;
                b = b/g;
                c = c/g;

                if(a<0 || (a==0 && b<0)){
                    a *= -1;
                    b *= -1;
                    c *= -1;
                }

                mp[{a, b, c}]++;
                m = max(m, mp[{a, b, c}]);
            }

        }
        cout<<m;
        return (1 + sqrt(1 + 4*m))/2;
    }
};