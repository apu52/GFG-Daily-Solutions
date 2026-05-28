class Solution {
 public:
 void solve(Node* root, int h, map<int, int> &mp) {
  if (!root)
   return;
  mp[h] += root->data;
  solve(root->left, h - 1, mp);
  solve(root->right, h + 1, mp);
 }
 vector<int> verticalSum(Node* root) {
  // code here
  map<int, int> mp;
  solve(root, 0, mp);
  vector<int> ans;
  for (auto &i:mp) {
   ans.push_back(i.second);
  }
  return ans;
 }
};
