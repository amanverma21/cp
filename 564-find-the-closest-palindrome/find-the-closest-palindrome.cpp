class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        candidates.insert(long(pow(10, l)) + 1);
        candidates.insert(long(pow(10, l - 1)) - 1);
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for ( long i = -1; i <= 1; ++i ) {
            string p = to_string(prefix + i);
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        long num = stol(n), minDiff = LONG_MAX, diff, minVal;
        candidates.erase(num);
        for ( long val : candidates ) {
            diff = abs(val - num);
            if ( diff < minDiff ) {
                minDiff = diff;
                minVal = val;
            } else if ( diff == minDiff ) {
                minVal = min(minVal, val);
            }
        }
        return to_string(minVal);
    }
};