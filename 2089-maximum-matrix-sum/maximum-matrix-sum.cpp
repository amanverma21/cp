class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int min_num = INT_MAX;
        int neg = 0;

        for(auto i : matrix) {
            for(int j : i) {
                if(j < 0) neg++;
                min_num = min(min_num, abs(j));
                ans += abs(j);
            }
        }

        if(neg%2==0) return ans;
        else return ans-2*min_num;
    }
};