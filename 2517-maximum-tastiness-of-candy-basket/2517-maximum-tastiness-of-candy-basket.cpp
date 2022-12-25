class Solution {
public:
    bool isPossible(vector<int>&price, int n,int k, int mid)
    {
    int count = 1;
    int prev = price[0];
    for (int i = 1; i < n; i++) {
        if (price[i] - prev >= mid) {
            prev = price[i];
            count++;
            if (count == k) {
                return true;
            }
        }
    }
    return false;
}
    int maximumTastiness(vector<int>& price, int k) {        
    int n=price.size();
    sort(price.begin(),price.end());
    int low = 0;
    int high = price[n - 1];
    int ans = 0;
    while (low <= high) {
         int mid = low+(high-low)/2;
        if (isPossible(price, n, k, mid)) {
            ans = mid;
             low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
    }
};