class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[j].size() >= words[i].size() &&
                    words[j].substr(0, words[i].size()) == words[i] &&
                    words[j].substr(words[j].size() - words[i].size()) == words[i]) {
                    count++;
                }
            }
        }
        return count;
    }
};