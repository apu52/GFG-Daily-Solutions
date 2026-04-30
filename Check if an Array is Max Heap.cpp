class Solution {
  public:
    virtual bool isMaxHeap(vector<int> &arr){
      int n=arr.size();
      
      for(int i=0; i<n; i++){
        int ch1=2*i+1;
        int ch2=2*i+2;
        
        if(ch1<n && arr[ch1]>arr[i]) return false; 
        if(ch2<n && arr[ch2]>arr[i]) return false; 
        
      }
      
      return true;
    }
};
