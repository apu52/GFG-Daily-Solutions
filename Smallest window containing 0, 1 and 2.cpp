class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int n = s.size();
        vector<int> v(3,0);
        int ans = INT_MAX;;
        int i = 0;
        int j = 0;
        while(j <= n){
            v[s[j]-'0']++;
            j++;
            
            while(v[0] && v[1] && v[2]){
                ans = min(ans, j-i);
                v[s[i]-'0']--;
                i++;
            }
        }
        if(ans != INT_MAX)
        return ans;
        return -1;
        
    }
};
