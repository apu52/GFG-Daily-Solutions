class Solution {
    public long subarrayXor(int arr[], int k) {
        
       int n = arr.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        int xor=0;
        int ans=0;
        for(int i=0; i<n; i++){
            xor^=arr[i];
            
            
            if(xor==k)
            ans++;
            
            if(map.containsKey(xor^k)){
                ans += map.get(xor^k);
            }
            
            map.put(xor, map.getOrDefault(xor,0)+1);
        }
        return ans;
    }
}
