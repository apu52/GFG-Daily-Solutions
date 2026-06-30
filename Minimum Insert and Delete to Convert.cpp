class Solution {
public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> pos;

        // Store index of each element in b
        for (int i = 0; i < b.size(); i++) {
            pos[b[i]] = i;
        }

        vector<int> lis;

        for (int x : a) {
            if (pos.find(x) != pos.end()) {
                int idx = pos[x];

                auto it = lower_bound(lis.begin(), lis.end(), idx);
                if (it == lis.end())
                    lis.push_back(idx);
                else
                    *it = idx;
            }
        }

        int lcs = lis.size();
        return (a.size() - lcs) + (b.size() - lcs);
    }
};
