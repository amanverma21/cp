class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = n * (n + 1) / 2;
        int k = n / m;
        int res = m * k * (k + 1) / 2;
        return ans - 2 * res;
    }
};