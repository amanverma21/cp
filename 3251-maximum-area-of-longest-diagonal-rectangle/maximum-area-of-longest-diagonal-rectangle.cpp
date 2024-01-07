class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        double maxDiagonal = 0;
        for (auto rectangle : dimensions) {
            int length = rectangle[0];
            int width = rectangle[1];
            double diagonal = sqrt(length * length + width * width);
            
            if (diagonal > maxDiagonal || (diagonal == maxDiagonal && length * width > maxArea)) {
                maxDiagonal = diagonal;
                maxArea = length * width;
            }
        }

        return maxArea;
    }
};
