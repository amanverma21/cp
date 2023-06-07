class Solution {
public:
    int minFlips(int a, int b, int c) {
         int xx = (a | b) ^ c;
         bitset<32> x(xx);
        bitset<32> y(a & b & xx);
        return x.count() + y.count();
    }
};