class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil(log10(buckets)/log10(minutesToTest/minutesToDie+1));
    }
};