class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       vector<long long> arr(n+1);
       long long int mod = 1000000007;
       for(int i=0;i<=n;i++){
           if(i<=2) arr[i]=1ll;
           else arr[i]=((arr[i-2]%mod)+(arr[i-3]%mod))%mod;
       }
       
       return arr[n];
    }
    
};
