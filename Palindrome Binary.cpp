class Solution {
public:
    int isPallindrome(long long N) {
        int left = 63; // max bits for long long
        
        // Find actual MSB position
        while (((N >> left) & 1) == 0) {
            left--;
        }
        
        int right = 0;
        
        while (left > right) {
            int leftBit = (N >> left) & 1;
            int rightBit = (N >> right) & 1;
            
            if (leftBit != rightBit) {
                return 0;
            }
            
            left--;
            right++;
        }
        
        return 1;
    }
};
