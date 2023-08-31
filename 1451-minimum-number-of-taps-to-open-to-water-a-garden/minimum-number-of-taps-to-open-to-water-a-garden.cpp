class Solution {
private:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        // using greedy
        // find max range which we can reach from 0th index
        // then, till that range find another max reachable range
        // do, till we reach last, and answer will be no. of times
        // we increase the range
        vector<pair<int, int>> range;
        for(int i = 0; i <= n; i++) {
            int l = i - ranges[i] < 0 ? 0 : i - ranges[i];
            range.push_back(make_pair(l, i + ranges[i]));
        }
        sort(range.begin(), range.end(), cmp);
        // using two pointer or sliding window
        int r = range[0].second;
        int nr = range[0].second;
        int count = 1;
        int i = 0;
        while(r < n) {
            count++;
            while(i <= n and range[i].first <= r) {
                nr = max(nr, range[i].second);
                i++;
            }
            if(nr > r) {
                r = nr;
            }
            else {
                break;
            }
        }
        if(r < n)   return -1;
        else    return count;
    }
};