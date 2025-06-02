class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        int temp=min(n,limit);
        for(int i=0;i<=temp;i++)
        {
            int p=n-i;
            if(p<=2*limit)
            {
                if(p<limit)
                {
                    ans+=((p)+1);
                }
                else
                {
                    ans+=(limit-(p-limit)+1);
                }
            }
        }
        return ans;
    }
};