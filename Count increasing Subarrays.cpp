class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n=arr.size();
        int start=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]<arr[i+1])
                continue;
            else{
                int size=i-start+1;
                if(size>=2) 
                    ans+=size*(size-1)/2;
                start=i+1;
            }
        }
        int size=n-start;
        if(size>=2)
            ans+=size*(size-1)/2;
        return ans;
    }
};
