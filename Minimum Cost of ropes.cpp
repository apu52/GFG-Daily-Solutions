class Solution {
  public:
  
    
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        long long cost=0;
        //sorted and smallest on top
        priority_queue<long long, vector<long long>, greater<long long>> pq; //min heap
        // priority_queue<long long> pq;
        for(auto i:arr) pq.push(i);
        while(pq.size()>1){
            long long x= pq.top();
            pq.pop();
            long long y= pq.top();
            pq.pop();
            cost+=x+y;
            pq.push(x+y);
        }
        
        return cost;
    }
};
