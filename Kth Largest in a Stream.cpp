class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()<k){
                ans.push_back(-1);
                continue;
            }
            if(pq.size()>k){
                pq.pop();
            }
             
            ans.push_back(pq.top());
            
        }
        return ans;
    }
};
