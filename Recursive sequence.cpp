class Solution{ 
public: 
    int mod = 1e9 + 7; 
    long long sequence(int n){ 
         
        long long ans = 0; 
        long long j = 1; 
         
        for(int i=1; i<=n; i++) { 
            long long val = 1; 
            int k = i; 
            while(k--) { 
                val = (val * j) % mod; 
                j++; 
            } 
             
            ans = ((ans%mod) + (val%mod)) % mod; 
        } 
         
        return ans; 
    } 
};
