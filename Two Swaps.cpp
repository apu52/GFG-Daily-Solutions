class Solution {
public:
    bool checkSorted(vector<int>& arr) {
        
        // code here.
           int n = arr.size();
        int swapCnt = 0;
        
        for(int i=0;i<n;i++){
            // if curr element is correct position then continue.
            if(arr[i] == i+1) continue;
            
            // if curr element is not correct position then try to 
            // do correct position using swap.
            while(arr[i] != i+1){
                swap(arr[arr[i] - 1],arr[i]);
                swapCnt++;
            }
        }
        
        // arr is already swap or swapCnt equal to 2.
        if(swapCnt == 2 || swapCnt == 0) return true;
        return false;
    
    }
};
     
