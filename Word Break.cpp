class Solution {
  public:
    int fun(int i, string &s, set<string> &st, vector<int> &dp){
        if(i==s.size())
            return 1;
        if(dp[i] != -1)
            return dp[i];
        
        string temp = "";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(st.find(temp) != st.end()){
                if(fun(j+1, s, st, dp))
                    return dp[i]=1;
            }
        }
        return dp[i]=0;    
    }
    
    int wordBreak(string &s, vector<string> &dic) {
        // code here
        int n = s.size();
        vector<int> dp(n+1, -1);
        set<string> st;
        for(auto z : dic){
            st.insert(z);
        }
        
        return fun(0, s, st, dp);
    }
};
