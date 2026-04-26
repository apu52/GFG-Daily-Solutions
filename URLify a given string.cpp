class Solution {
  public:
    string URLify(string &s) {
       string ans ;
        for(auto ch : s){
            if(ch==' ') ans += "%20";
            else ans += ch;
        }
        return ans;
    }
};
