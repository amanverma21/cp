class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;
        n--;
        while(n>0){

        }
        int i=0,j=0;
        while(n>>j){
            while((ans>>i)&1==1){
                i++;
            }
                ans+=(n>>j&1)*pow(2,i);
                i++;
                j++;
        }
        return ans;
    }
};