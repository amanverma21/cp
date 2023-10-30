class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto cmp = [](int a, int b) {
            int popcount_a = __builtin_popcount(a);
            int popcount_b = __builtin_popcount(b);
            return popcount_a == popcount_b ? a < b : popcount_a < popcount_b;
        };
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};