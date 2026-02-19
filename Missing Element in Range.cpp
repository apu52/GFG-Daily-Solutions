class Solution {
  public:
  bool bs(vector<int>& arr,int element)
  {
      int low = 0;
      int high = arr.size() - 1;
      while(low <= high)
      {
          int mid = (low + high)/2;
          if(arr[mid] < element)
          {
              low = mid + 1;
          }
          else if(arr[mid] > element)
          {
              high = mid - 1;
          }
          else
          {
              return true;
          }
      }
      return false;
  }
  
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        
        vector<int>ans;
        sort(arr.begin(),arr.end());
        for(int i = low;i <= high;i++)
        {
            if(bs(arr,i) == false)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
