class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        bool flag = false;
        int n = arr.size();
        
        for (int i = 0; i < n; i++)  {
            if (arr[i] == 1)
                flag = true;
            
            if (arr[i] < 1 or arr[i] > n)
                arr[i] = 1;
        }
        
        if (not flag)
            return 1;
        
        for (int i = 0; i < n; i++)  {
            int id = abs(arr[i]);
            arr[id - 1] = -1*abs(arr[id-1]);
        }
        
        for (int i = 0; i < n; i++)  {
            if (arr[i] > 0)
                return i + 1;
        }
        
        return n + 1;
    }
};
