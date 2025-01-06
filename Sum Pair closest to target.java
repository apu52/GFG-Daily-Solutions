class Solution {
    public List<Integer> sumClosest(int[] arr, int target) {
        Arrays.sort(arr);
        int n=arr.length;
        int l=0, r=n-1;
        int minDiff=Integer.MAX_VALUE;
        List<Integer> ans = new ArrayList<>();
        
        while(l<r){
            int sum = arr[l]+arr[r];
            
            if(Math.abs(target-sum)<minDiff){
                minDiff = Math.abs(target-sum);
                ans = Arrays.asList(arr[l],arr[r]);
            }
            
            
            if(sum<target){
                l++;
            }else if(sum>target){
                r--;
            }else{
                return ans;
            }
        }
        
        return ans;
    }
}
