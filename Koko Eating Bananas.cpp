class Solution {
  public:
   
    int calculateHours(vector<int>& arr, int rate) {
        int hours = 0;
        for (int bananas : arr) {
            hours += (bananas + rate - 1) / rate; 
        }
        return hours;
    }

    int kokoEat(vector<int>& arr, int k) {
        int low = 1, high = *max_element(arr.begin(), arr.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            
            int hours = calculateHours(arr, mid);

            if (hours <= k) {
                
                result = mid;
                high = mid - 1;
            } else {
               
                low = mid + 1;
            }
        }

        return result;
    }
};
