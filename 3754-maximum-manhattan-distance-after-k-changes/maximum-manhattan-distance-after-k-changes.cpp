class Solution {
public:
    int maxDistance(string s, int k) {
        int latitude = 0, longitude = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case 'N':
                latitude++;
                break;
            case 'S':
                latitude--;
                break;
            case 'E':
                longitude++;
                break;
            case 'W':
                longitude--;
                break;
            }
            int currentDistance = abs(latitude) + abs(longitude);
            int boostedDistance = currentDistance + 2 * k;
            ans = max(ans, min(boostedDistance, i + 1));
        }
        return ans;
    }
};