class Solution {
  public:
    int maxLength(string str) {
        // code here
        int ans = 0, n = str.length();
        stack<int> s;
        // let say dp[i] repreesent the longest valid substring ending at i i.e string having str[i] as its last character
        int dp[n];
        for(int i = 0; i<n; i++){
            if(str[i]=='('){
                s.push(i);
                dp[i] = 0;
            }
            else{
                if(!s.empty()){
                    int j = s.top();
                    s.pop();
                    int before_streak = 0;
                    if(j-1 >= 0) before_streak = dp[j-1];// to address ()().. to add any before streak
                    ans = max(ans,i-j+1+before_streak); // the range of i-j is entirely valid
                    // ((())) kind of things are addressed by i-j+1
                    dp[i] = i-j+1+before_streak;
                }
                else{
                   dp[i] = 0; 
                }
            }
        }
        return ans;
    }
};
