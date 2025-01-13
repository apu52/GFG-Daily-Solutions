class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=0;
        
        int low=0,high=n-1;
        
        while(low<high){
            int area=(high-low) * (min(arr[low],arr[high]));
            ans=max(ans,area);
            
            if(arr[low]<arr[high])
                low++;
            else    
                high--;
        }
        
        return ans;
    }
};
