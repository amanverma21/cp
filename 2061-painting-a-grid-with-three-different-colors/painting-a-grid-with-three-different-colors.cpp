class Solution
{
public:
    bool valid(int mask,int m)
    {
        int prev=-1;
        for(int j=0;j<m;j++)
        {
            if(prev==mask%3)
            {
                return false;
            }
            prev=mask%3;
            mask/=3;
        }
        return true;
    }
    
    int colorTheGrid(int m, int n)
    {
        const int mod=1e9+7;
        int l=pow(3,m);
        bitset<243> list[l];
        bitset<243> v;
        for(int i=0;i<l;i++)
        {
            if(valid(i,m))
            {
                v.set(i);
            }
        }
        for(int i=0;i<l;i++)
        {
            if(v.test(i)==false)
            {
                continue;
            }
            for(int j=0;j<l;j++)
            {
                if(list[i].test(j)||v.test(j)==false)
                {
                    continue;
                }
                int temp1=i;
                int temp2=j;
                int f=1;
                for(int k=0;k<m;k++)
                {
                    if(temp1%3==temp2%3)
                    {
                        f=0;
                        break;
                    }
                    temp1/=3;
                    temp2/=3;
                }
                if(f)
                {
                    list[i].set(j);
                    list[j].set(i);
                }
            }
        }
        int dp[2][l];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<l;i++)
        {
            if(v.test(i))
            {
                dp[0][i]=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            memset(dp[i%2],0,sizeof(dp[0]));
            for(int j=0;j<l;j++)
            {
               
                for(int k=0;k<l;k++)
                {
                    if(list[j].test(k))
                    {
                        dp[i%2][j]+=dp[(i-1)%2][k];
                        dp[i%2][j]%=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<l;i++)
        {
            ans+=dp[(n-1)%2][i];
            ans%=mod;
        }
        return ans;
    }
};