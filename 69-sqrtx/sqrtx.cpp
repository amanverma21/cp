class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int ans = 1;
        if (x == 1) return 1;
        while(low<=high){
            long long mid = (low+high)/2;
            long long val = (mid * mid);
            // for(int i=0;i<x;i++){
            // }
                if(val<=x)
                {
                    ans = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
        }
        return ans;
    }
};