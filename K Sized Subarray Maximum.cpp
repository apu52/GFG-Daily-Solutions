class Solution {
    public ArrayList<Integer> max_of_subarrays(int k, int arr[]) {
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        Deque<Integer> dq = new ArrayDeque<>();
        
        for(int i=0;i<k;i++){
            while(!dq.isEmpty() && arr[ dq.peekLast() ]<= arr[i]){
                dq.removeLast();
            }
            
            dq.addLast(i);
        }
        
        ans.add(arr[ dq.peekFirst() ]);
        
        for(int i=k;i<n;i++){
            
            //remove out of window element
            if(dq.peekFirst()<=i-k){
                dq.removeFirst();
            }
            
            //include current element
            //in decreasing order
            while(!dq.isEmpty() && arr[ dq.peekLast() ]<= arr[i]){
                dq.removeLast();
            }
            
            dq.addLast(i);
            
            ans.add(arr[ dq.peekFirst() ]);
            
            
        }
        
        
        return ans;
    }
}
