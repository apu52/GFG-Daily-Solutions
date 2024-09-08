class Solution {
  public:
  

    int minJumps(vector<int>& arr) {
        // Your code here
        int n= arr.size();
        int jump=0;
        int nextmove=0; //till here we are able to reach
        int level=0; 
        if(n<=1) return 0;
        if(arr[0]==0) return -1;
        
        for(int i=0;i<n;i++){
            nextmove= max(nextmove,arr[i]+i);
            
            if(level==i){
                jump++;
                level= nextmove;
                if(level>=n-1) return jump;
            }
        }
        
        return -1;
    }
};
