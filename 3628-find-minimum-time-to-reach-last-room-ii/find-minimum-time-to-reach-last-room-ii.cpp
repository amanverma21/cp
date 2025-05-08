class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTimeGrid) {
        int rowCount = moveTimeGrid.size();
        int colCount = moveTimeGrid[0].size();
        
        vector<vector<int>> minArrivalTime(rowCount, vector<int>(colCount, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, 0}); 
        moveTimeGrid[0][0] = 0;  
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  
        while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop(); 
            int currentTime = current[0];
            int currentRow = current[1];
            int currentCol = current[2]; 
            if (currentTime >= minArrivalTime[currentRow][currentCol]) continue; 
            minArrivalTime[currentRow][currentCol] = currentTime; 
            if (currentRow == rowCount - 1 && currentCol == colCount - 1) return currentTime; 
            for (auto& dir : directions) {
                int nextRow = currentRow + dir[0];
                int nextCol = currentCol + dir[1]; 
                if (nextRow >= 0 && nextRow < rowCount &&
                    nextCol >= 0 && nextCol < colCount &&
                    minArrivalTime[nextRow][nextCol] == INT_MAX) { 
                    int moveCost = (currentRow + currentCol) % 2 + 1;
                    int availableTime = max(moveTimeGrid[nextRow][nextCol], currentTime);
                    int arrivalTime = availableTime + moveCost; 
                    minHeap.push({arrivalTime, nextRow, nextCol});
                }
            }
        } 
        return -1;  
    }
};