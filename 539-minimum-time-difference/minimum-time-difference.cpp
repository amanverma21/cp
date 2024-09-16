class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> ans;
        for (const string& time : timePoints) {
            ans.push_back(solve(time));
        }
        sort(ans.begin(), ans.end());
        for (int i = 1; i < ans.size(); i++) {
            res = min(res, ans[i] - ans[i - 1]);
        }
        res = min(res, 1440 + ans[0] - ans.back());
        return res;
    }

private:
    int solve(const string& time) {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 5));
        return hour * 60 + minute;
    }
};