class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(),  c.end());
        
        int diff=INT_MAX, sum=INT_MAX, an=a.size(), bn=b.size(), cn=c.size();
        int i=0, j=0,k=0;
        
        vector<int>v(3);
        
        while(i<an && j<bn && k<cn){
            int n1=a[i], n2=b[j], n3=c[k];
            int mx=max(n1, max(n2,n3));
            int mn=min(n1, min(n2,n3));
            if(mx-mn < diff || (mx-mn==diff && sum>n1+n2+n3)){
                v[0]=n1, v[1]=n2, v[2]=n3;
                sum=n1+n2+n3;
                diff=mx-mn;
                sort(v.rbegin(), v.rend());
            }
            
            if(mn==n1)i++;
            else if(mn==n2)j++;
            else k++;
            
        }
        
        return v;
    }
};
