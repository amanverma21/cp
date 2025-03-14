class Solution {
    int n;
    bool isPossible(int mid , long long k, vector<int>& candies){
        long long number =0;
        for(int i=0;i<n;i++){
            if(candies[i] < mid) continue;
            number += candies[i]/mid;
        }
        if(number >= k) return true;
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        n = candies.size();
        int ans =0;
        sort(candies.begin() , candies.end());
        int l =1;
        int r = 0;
        long long total =0;
        for(int i=0;i<n;i++) {
            r= max(r, candies[i]);
            total += candies[i];
        }
        if(total < k) return 0;
        while(r >= l){
            int mid = l + (r-l)/2;
            if(isPossible(mid, k, candies)){
                ans = mid;
                l= mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};