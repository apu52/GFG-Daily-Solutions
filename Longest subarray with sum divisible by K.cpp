class Solution{ 
public:  
 int longSubarrWthSumDivByK(int arr[], int n, int k) 
 { 
     map<int,int> m; 
        m[0]=-1; 
        int sum=0; 
        int rem; 
        int largest=0; 
        for(int i=0;i<n;i++) 
        { 
            sum+=arr[i]; 
            rem=sum%k; 
            if(rem<0) rem+=k; 
            auto itr=m.find(rem); 
            if(itr!=m.end())  
            { 
                if((i-itr->second)>largest) largest=i-itr->second; 
            } 
            else m[rem]=i; 
       } 
       return largest; 
 } 
};
