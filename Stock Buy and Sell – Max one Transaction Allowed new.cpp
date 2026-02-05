class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int minsofar=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            minsofar=min(prices[i],minsofar);
            profit=max(profit,prices[i]-minsofar);
        }
        
        return profit;
    }
};
