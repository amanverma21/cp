class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = key.size();
        int m = ring.size();
        int dp[n + 1][m]; 
        // dp[i][j] = min steps to make key[i...n-1] when ring[j] is at 12:00
        // dp[i][j] = steps to make key[i] + min(dp[i + 1][pj]) where ring[pj] will be at 12 before making key[i] and ring[j] would be at 12:00 after making
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = 999999;
            }
        }
        for(int j = 0; j < m; j++) {
            dp[n][j] = 0;
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < m; j++) { // current pos in ring at 12:00
                for(int nj = 0; nj < m; nj++) { // new ring position at 12:00
                    if(key[i] == ring[nj]) {
                        int steps = abs(nj - j);
                        int rot = min(steps, m - steps);
                        dp[i][j] = min(dp[i][j], rot + dp[i + 1][nj]);
                    }
                }
            }
        }
        return dp[0][0] + n;
        
    }
};