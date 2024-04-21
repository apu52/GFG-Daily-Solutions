class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {   
        int n=array.size();
        int j=0;
        int k=n-1;
        for(int i=0;i<n;i++){
            if(array[i]<a) {
                swap(array[i],array[j]);
                j++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(array[i]>b){
                swap(array[i],array[k]);
                k--;
            }
        }
    }
};
