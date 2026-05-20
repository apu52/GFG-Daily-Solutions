class Solution {
  public:
    bool isProduct(vector<int>& a, long long target) {
        map<long long,bool>mpp;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(target==0 && a[i]==0)return true;
            if(a[i]==0)continue;
            if(target%a[i]!=0)continue;
            long long q=target/a[i];
            if(mpp[q])return true;
            mpp[a[i]]=true;
        }
        return false;
        
    }
};
