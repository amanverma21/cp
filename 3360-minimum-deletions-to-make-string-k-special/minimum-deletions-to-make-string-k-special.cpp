class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<long long> count(26, 0);
        for (int i = 0; i < word.length(); i++) {
            count[word[i] - 'a']++;
        }
        sort(count.begin(), count.end());
        long long ans = LLONG_MAX;
        for (int i = 0; i < 26; i++) {
            long long curr = 0;
            for (int j = 0; j < i; j++) {
                curr+=count[j];
            }
            for (int j = i; j < 26; j++) {
                if (count[j] > count[i] + k) {
                    curr+=(count[j] - (count[i] + k));
                }
            }
            ans = min(ans, curr);
        }
        return ans;
    }
};