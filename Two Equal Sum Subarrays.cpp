class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> pre(n);
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=arr[i] + pre[i-1];
        }
        int total=pre[n-1];
        for(int val : pre){
            if(total-val==val){
                return true;
                break;
            }
        }
        return false;
    }
};
