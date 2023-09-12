class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        unordered_set<int> freqold;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<int> maxHeap;
        for (auto freq : freq) {
            maxHeap.push(freq.second);
        }

        int deletions = 0;
        while (!maxHeap.empty()) {
            int curFreq = maxHeap.top();
            maxHeap.pop();
            
            while (curFreq> 0 && freqold.count(curFreq)) {
                curFreq--;
                deletions++;
            }
            
            freqold.insert(curFreq);
        }
        return deletions;
    }
};