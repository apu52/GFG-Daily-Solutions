class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,0);
        
        stack<array<int,2>>st1,st2;
        vector<int>lefg(n,0),rigg(n,0),lefs(n,0),rigs(n,0);
        
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st1.empty() and arr[i]>=st1.top()[0]){
                cnt+=st1.top()[1];
                st1.pop();
            }
            lefg[i]=cnt;
            st1.push({arr[i],cnt});
        }
        
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st2.empty() and arr[i]>st2.top()[0]){
                cnt+=st2.top()[1];
                st2.pop();
            }
            rigg[i]=cnt;
            st2.push({arr[i],cnt});
        }
        
        while(!st1.empty()) st1.pop();
        while(!st2.empty()) st2.pop();
        
        
        
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st1.empty() and arr[i]<=st1.top()[0]){
                cnt+=st1.top()[1];
                st1.pop();
            }
            lefs[i]=cnt;
            st1.push({arr[i],cnt});
        }
        
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st2.empty() and arr[i]<st2.top()[0]){
                cnt+=st2.top()[1];
                st2.pop();
            }
            rigs[i]=cnt;
            st2.push({arr[i],cnt});
        }
        
        int sm1=0;
        int sm2=0;
        
        for(int i=0;i<n;i++){
            int totalcnt= lefg[i]*rigg[i];
            int tsm= totalcnt*arr[i];
            sm1+=tsm;
        }
        for(int i=0;i<n;i++){
            int totalcnt= lefs[i]*rigs[i];
            int tsm= totalcnt*arr[i];
            sm2+=tsm;
        }
        
        return sm1-sm2;
    }
};
