class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        int maxDistance = 0;

        for (int i = 1; i < arrays.size(); i++) {
            int currentMin = arrays[i][0];
            int currentMax = arrays[i].back();

            maxDistance = max(maxDistance, abs(currentMax - minVal));
            maxDistance = max(maxDistance, abs(maxVal - currentMin));

            minVal = min(minVal, currentMin);
            maxVal = max(maxVal, currentMax);
        }

        return maxDistance;
    }
};