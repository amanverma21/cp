class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int i = 0, j = 0;
        vector<int> ans;
        int n1 = arr1.size(), n2 = arr2.size();
        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) ans.push_back(arr1[i++]);
            else ans.push_back(arr2[j++]);
        }
        while (i < n1) ans.push_back(arr1[i++]);
        while (j < n2) ans.push_back(arr2[j++]);
        int n = n1 + n2;
        if (n % 2 == 1) return ans[n / 2];
        else return (double)(ans[n / 2] + ans[n / 2 - 1]) / 2.0;
    }
};
