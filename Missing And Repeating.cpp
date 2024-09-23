class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int miss,rep;
        
        for(int i=0;i<arr.size();i++){
            int tar = abs(arr[i])-1;
            
            if(arr[tar] < 0){
                rep = abs(arr[i]);
            }
            else{
                arr[tar] = -arr[tar];
            }
        }
        
        //Missing
        for(int i=0;i<arr.size();i++){
            if(arr[i] > 0){
                miss = i+1;
                break;
            }
        }
        return {rep,miss};
    }
};
