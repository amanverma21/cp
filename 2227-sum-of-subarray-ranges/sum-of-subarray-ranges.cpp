class Solution {
public:
    const long long mod = 1e9+7;
    long long subArrayRanges(vector<int>& arr) {
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            long long minVal = arr[i];
            long long maxVal = arr[i];
            for(int j = i; j < arr.size(); j++) {
                minVal = min(minVal, (long long)arr[j]);
                maxVal = max(maxVal, (long long)arr[j]); 
                sum = sum + maxVal - minVal;
            }
        }
        return sum;
    }
};
