class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size();
        int m = b.size();
        if(n > m) return kthElement(b, a, k); // smaller array first
        
        int low = max(0, k - m);
        int high = min(k, n);
        
        while(low <= high){
            int mid1 = (low + high)/2;
            int mid2 = k - mid1;
            
            int l1 = (mid1 > 0) ? a[mid1-1] : INT_MIN;
            int l2 = (mid2 > 0) ? b[mid2-1] : INT_MIN;
            int r1 = (mid1 < n) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < m) ? b[mid2] : INT_MAX;
            
            if(l1 <= r2 && l2 <= r1) return max(l1, l2);
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return -1;
    }
};
