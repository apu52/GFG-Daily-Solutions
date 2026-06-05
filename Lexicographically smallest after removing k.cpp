class Solution {
 public:
 bool isPowOf2(int n) {
  return !(n & (n - 1));
 }
 
 string lexicographicallySmallest(string &s, int k) {
  // code here
  
  int n = s.size();
  if (isPowOf2(n)) {
   k = k / 2;
  } else {
   k = 2 * k;
  }
  
  if (n == 0 || k >= n) {
   return "-1";
  }
  
  string ans = "";
  
  ans += s[0];
  
  for (int i = 1; i < n; i++) {
   while (ans.size() >= 1 && s[i] < ans[ans.size() - 1] && k > 0) {
    ans.pop_back();
    k--;
   }
   
   ans.push_back(s[i]);
  }
  
  while (ans.size() >= 1 && k > 0) {
   ans.pop_back();
   k--;
  }
  
  return ans;
  
 }
};
