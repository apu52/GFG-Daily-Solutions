class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        int l=a.size();
        int m=b.size();
        int n=c.size();
        vector<int>ans;
        int idx1=0,idx2=0,idx3=0;
        while(idx1<l && idx2<m && idx3<n){
            if(a[idx1]==b[idx2] && b[idx2]==c[idx3]){
                if(ans.size()==0){
                ans.push_back(a[idx1]);
                }
                else{
                    if(ans.back()!=a[idx1]){
                        ans.push_back(a[idx1]);
                    }
                }
                idx1++;
                idx2++;
                idx3++;
            }
            else
            if(a[idx1]==b[idx2] && a[idx1]>c[idx3]){
                idx3++;
            }
            else
            if(b[idx2]==c[idx3] && b[idx2]>a[idx1]){
                idx1++;
            }
            else
            if(a[idx1]==c[idx3] && a[idx1]>b[idx2]){
                idx2++;
            }
            else
            if(a[idx1]>max(b[idx2],c[idx3])){
                idx2++;
                idx3++;
            }
            else
            if(b[idx2]>max(a[idx1],c[idx3])){
                idx1++;
                idx3++;
            }
            else
            {
                idx1++;
                idx2++;
            }
        }
        
        return ans;
    }
};
