class Solution {
    public int countBuildings(int[] height) {
        int prev = -1, ans=0;
        for(int i:height){
            if(i>prev){
                ans++;
                prev=i;
            }
        }
        return ans;
    }
}
