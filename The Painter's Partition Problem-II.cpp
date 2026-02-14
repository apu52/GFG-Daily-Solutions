class Solution {
  public:

    // function to check if k painters can paint with max time = limit
    bool canPaint(vector<int>& arr, int k, long long limit){
        int painters = 1;
        long long curr = 0;

        for(int i = 0; i < arr.size(); i++){
            
            // if single board itself exceeds limit -> impossible
            if(arr[i] > limit) return false;

            // add board to current painter
            if(curr + arr[i] <= limit){
                curr += arr[i];
            }
            else{
                // need new painter
                painters++;
                curr = arr[i];

                if(painters > k) return false;
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {

        long long low = 0, high = 0;

        // calculate search range
        for(int x : arr){
            low = max(low, (long long)x);  // minimum time
            high += x;                     // maximum time
        }

        long long ans = high;

        // binary search
        while(low <= high){
            long long mid = (low + high) / 2;

            if(canPaint(arr, k, mid)){
                ans = mid;
                high = mid - 1;   // try smaller time
            }
            else{
                low = mid + 1;    // need more time
            }
        }

        return (int)ans;
    }
};
