// gfg 160 problem today(23/11/24) 

class Solution {
    int getMinDiff(int[] arr, int k) {
        // code here
        int n = arr.length;
        
        Arrays.sort(arr);

        int min = arr[n-1] - arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] - k < 0) {
                continue;
            }

            int currentMin = Math.max(arr[n-1] - k, arr[i-1] + k) - Math.min(arr[0] + k, arr[i] - k);
            min = Math.min(min, currentMin);
        }

        return min;
    }
}
