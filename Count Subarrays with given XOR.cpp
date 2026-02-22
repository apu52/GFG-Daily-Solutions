class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = size(arr);
        unordered_map<int,int> mp;
        int preXor = 0, count = 0;
        for(int i = 0; i < n; i++){
            preXor ^= arr[i];
            if(preXor == k) 
                count++;
            if(mp.find(preXor ^ k) != mp.end())
                count += mp[preXor ^ k];
            mp[preXor]++;
        }
        return count;
    }
};
