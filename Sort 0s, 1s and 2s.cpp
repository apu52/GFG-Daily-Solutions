class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int i=0;
        int j=0;
        int k= arr.size()-1;
        
        while(j<=k){
            if(arr[j]==0){
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
            else if(arr[j]==2){
                swap(arr[j],arr[k]);
                k--;
                // j++;
            }
            else{
                j++;
            } 
        }
        
        return;
    }
};
