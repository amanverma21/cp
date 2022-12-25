class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ans = 0;
    for (int i = 0, idx2 = 0; i < forts.size(); ++i)
        if (forts[i] != 0) {
            if (forts[idx2] == -forts[i])
                ans = max(ans, i - idx2 - 1);
            idx2 = i;
        }
    return ans;
    }
};