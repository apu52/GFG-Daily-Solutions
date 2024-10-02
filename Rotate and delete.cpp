class Solution {
    public static int rotateDelete(ArrayList<Integer> arr) {
        int n = arr.size(), k=1;
        while(n>1){
            arr.add(0,arr.remove(n-1));
            
            int id = n-k;
            if(id<0)    id=0;
            arr.remove(id);
            
            k++;
            n--;
        }
        return arr.get(0);
    }
}
