class Solution {
  public:
    string armstrongNumber(int n){
        string ans = to_string(n);
        if((pow((ans[0]-'0'),3)+pow((ans[1]-'0'),3)+pow((ans[2]-'0'),3))==n) return "Yes";
        return "No";
    }
};
