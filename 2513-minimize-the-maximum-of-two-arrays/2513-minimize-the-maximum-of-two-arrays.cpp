class Solution {
public:
   
int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
    return max({getMax(cnt1, d1), getMax(cnt2, d2), getMax(cnt1 + cnt2, d1, d2) });
}
    int getMax(int cnt, long long d1, long long d2 = 1) {
    long long d = lcm(d1, d2);
    return cnt + cnt / (d - 1) - (cnt % (d - 1) ? 0 : 1);
}
};