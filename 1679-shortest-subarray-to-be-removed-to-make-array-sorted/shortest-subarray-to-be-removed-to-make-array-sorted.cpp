class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l=0,r=n-1;
        while(l+1<n && arr[l] <= arr[l+1]) l++;
        if(l==n-1) return 0;
        while(r-1>=0 && arr[r] >= arr[r-1]) r--;
        int res = min(n-l-1,r),i=0,j=r;
        while(i<=l && j<n){
            if(arr[i] <= arr[j]){
                res = min(res,j-i-1);
                i++;
            }else{
                j++;
            }
        } 
        return res;
    }
};