class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // use prefix sum of odd & even elements
        int n = arr.size();
        int matches = 0;
        
        // calculate even and odd elements
        int oddSum = 0;
        int evenSum = 0;
        for(int i=0; i<n; i++)
        {
            // i & 1 return true for odd numbers
            if(i & 1)
            {
                oddSum += arr[i];
            }
            else
            {
                evenSum += arr[i];
            }
        }
        
        // current calculated sum
        int curOdd = 0;
        int curEven = 0;
        for(int i=0; i<n; i++)
        {
            // reduce current element from odd/even sum
            if(i & 1)
            {
                oddSum -= arr[i];
            }
            else
            {
                evenSum -= arr[i];
            }
            
            // check if current sum + rest of the sum match
            if( curOdd + evenSum == curEven + oddSum)
            {
                matches++;
            }
            
            // add current element to cur odd/even
            if(i & 1)
            {
                curOdd += arr[i];
            }
            else
            {
                curEven += arr[i];
            }
        }
        
        return matches;
    }
};
