class Solution {
  public:
    const int mod = 1e9+7;
    int countWays(string s1, string s2) {
        vector<int> prev(s2.length()+1, 0);
        vector<int> curr(s2.length()+1, 0);
        for(int i = 0; i <= s1.length(); i++){
            prev[0] = 1;
        }
        for(int i = 1; i <= s1.length(); i++){
            curr[0] = 1;
            for(int j = 1; j <= s2.length(); j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = (prev[j-1]%mod + prev[j]%mod)%mod;
                }
                else{
                    curr[j] = prev[j]%mod;
                }
            }
            prev = curr;
        }
        return prev[s2.length()];
    }
};
