class Solution {
  public:
    int maxOnes(vector<int>&v){
        int n = v.size();
        int one = 0;
        for(int i=0;i<n;i++){
            if(v[i]==1) one++;
        }
        
        int maxgain = 0;
        int c = 0;
        
        for(int i=0;i<n;i++){
            if(v[i]==0) c++;
            else c--;
            
            if(c < 0) c = 0;
            maxgain = max(maxgain,c);
        }
        return one+maxgain;
    }
};
