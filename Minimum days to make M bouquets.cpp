class Solution {
public:
    bool canMakeBouquets(int m, int k, vector<int>& arr, int day) {
        int bouquetCount = 0;
        int flowersInBouquet = 0;
        
        for (int bloomDay : arr) {
            if (bloomDay <= day) {
                flowersInBouquet++; 
            } else {
                flowersInBouquet = 0; 
            }
            
            if (flowersInBouquet == k) {
                bouquetCount++;
                flowersInBouquet = 0; 
            }
        }
        
        return bouquetCount >= m; 
    }
    
    int minDaysBloom(int m, int k, vector<int>& arr) {
        int n = arr.size();
        
        
        if (n < m * k) {
            return -1;
        }
        
        int low = *min_element(arr.begin(), arr.end()); 
        int high = *max_element(arr.begin(), arr.end()); 
        
        int result = high;
        
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMakeBouquets(m, k, arr, mid)) {
                result = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        
        return result;
    }
};
