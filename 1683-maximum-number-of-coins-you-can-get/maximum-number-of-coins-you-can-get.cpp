class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int sum = 0;
        for (int l = 0, r = piles.size() - 1; l < r; l += 2, r--) {
            sum += piles[l + 1];
        }
        return sum;
    }
};