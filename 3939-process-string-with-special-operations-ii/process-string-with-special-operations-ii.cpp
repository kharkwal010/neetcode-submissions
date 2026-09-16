class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        int n = s.size();

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i] = len;

            char c = s[i];

            if (c == '*') {
                len = max(len - 1, 0LL);
            }
            else if (c == '#') {
                len *= 2;
            }
            else if (c != '%') {
                len++;
            }

            pref[i + 1] = len;
        }

        if (len <= k) return '.';

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                long long half = len / 2;

                if (k >= half)
                    k -= half;

                len = half;
            }
            else if (s[i] == '%') {
                k = len - 1 - k;
            }
            else if (s[i] == '*') {
                len = pref[i];
            }
            else {
                len--;

                if (len == k)
                    return s[i];
            }
        }

        return '.';
    }
};