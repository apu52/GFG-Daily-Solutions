class Solution {
  public:
     int mod=1e9+7;
    long long bin(int i, int p)
    {
        if(p==0)
        return 1;
        if(p==1)
        return i;
        long long x=bin(i,p/2);
        if(p%2)
        return (((x*x)%mod)*i)%mod;
        return (x*x)%mod;
    }
    int computeValue(int n) {
        // code here
       
        vector<long long>v(n+1);
        v[0]=1;
        for(int i=1;i<=n;i++)
        {
            v[i]=(v[i-1]*(n-i+1))%mod;
            v[i]=(v[i]*bin(i,mod-2))%mod;
        }
        long long ans=0;
        for(int i=0;i<=n;i++)
        {
            ans=(ans+v[i]%mod*v[i]%mod)%mod;
        }
        return ans;
        
    }
};
