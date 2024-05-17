class Solution {
    public int findPair(int n, int x, int[] arr) {
        int ans = 0;
        Set<Integer> set = new HashSet<>();
        Arrays.sort(arr);
        for (int i = 0; i < n; i++){
            if (set.contains(arr[i]-x)) ans++;
            set.add(arr[i]);
        }
        return ans == 0 ? -1 : 1;
    }
}
