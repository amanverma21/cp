
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int days) {
        int length = jobDifficulty.size();
        if (days > length) return -1;
        
        vector<vector<int>> minDifficulties(days, vector<int>(length));
        
        for (int i = 1; i < days; ++i) {
            fill(minDifficulties[i].begin(), minDifficulties[i].end(), INT_MAX);
        }
        
        int maxDiff = 0; 
        int i = 0;
        while (i <= length - days) {
            maxDiff = max(maxDiff, jobDifficulty[i]);
            minDifficulties[0][i] = maxDiff;
            ++i;
        }
        
        int currentDay = 1;
        while (currentDay < days) {
            int to = currentDay;
            while (to <= length - days + currentDay) {
                int currentJobDifficulty = jobDifficulty[to];
                int result = INT_MAX;
                int j = to - 1;
                while (j >= currentDay - 1) {
                    result = min(result, minDifficulties[currentDay - 1][j] + currentJobDifficulty);
                    currentJobDifficulty = max(currentJobDifficulty, jobDifficulty[j]);
                    --j;
                }
                minDifficulties[currentDay][to] = result; 
                ++to;
            }
            ++currentDay;
        }
        
        return minDifficulties[days - 1][length - 1]; 
    }
};

