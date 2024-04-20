class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        
    int i=0,j=0;
    vector<int> uni;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
          if (uni.size() == 0 || uni.back() != arr1[i]) {
            uni.push_back(arr1[i]);
          }
          i++;
        }else{
          if (uni.size() == 0 || uni.back() != arr2[j]) {
            uni.push_back(arr2[j]);
          }
          j++;
        }


    }
    while(i<n){
          if (uni.back() != arr1[i]) {
            uni.push_back(arr1[i]);
          }
          i++;  
    }
    while(j<m){
          if (uni.back() != arr2[j]) {
            uni.push_back(arr2[j]);
          }
          j++;
    }


return uni;
    }
};
