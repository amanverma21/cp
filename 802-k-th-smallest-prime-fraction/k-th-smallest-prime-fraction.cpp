class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxHeap.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});

                if (maxHeap.size() > k)
                    maxHeap.pop();
            }
        }

        return {maxHeap.top().second.first, maxHeap.top().second.second};
    }
};