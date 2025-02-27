class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size(), ans = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                int c=2, p=A[i], q=A[j], k=j;
                for(;;){
                    k = lower_bound(A.begin()+k+1,A.end(),p+q) - A.begin();
                    if(k<n && A[k]==p+q) p=q, q=A[k], c++;
                    else break;
                }
                ans = max(ans,c);
            }
        return ans<3 ? 0 : ans;
    }
};
