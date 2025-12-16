class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        string s = s1;
        for(char ch:s1){
            s+=ch;
        }
        if(s1==s2){
            return true;
        }
        int m = s2.length();
        int n = s1.length();
        if(n!=m)    return false;
        return (s.find(s2)!=string::npos);
    }
};
