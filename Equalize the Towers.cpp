#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long getCost(vector<int>& heights, vector<int>& cost, int target) {
        long long totalCost = 0;
        
        for(int i = 0; i < heights.size(); i++) {
            totalCost += 1LL * abs(heights[i] - target) * cost[i];
        }
        
        return totalCost;
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        
        int left = *min_element(heights.begin(), heights.end());
        int right = *max_element(heights.begin(), heights.end());
        
        long long answer = LLONG_MAX;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            long long cost1 = getCost(heights, cost, mid);
            long long cost2 = getCost(heights, cost, mid + 1);
            
            answer = min(cost1, cost2);
            
            if(cost1 < cost2)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return answer;
    }
};
