class Solution {
public:
    bool isValid(const string& s) {
        int bal = 0;
        for (char c : s) {
            if (c == '(')
                bal++;
            else if (c == ')') {
                if (bal == 0)
                    return false;
                bal--;
            }
        }
        return bal == 0;
    }

    vector<string> validParenthesis(string& s) {
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        vector<string> ans;
        bool found = false;

        while (!q.empty()) {
            int sz = q.size();

            for (int k = 0; k < sz; k++) {
                string cur = q.front();
                q.pop();

                if (isValid(cur)) {
                    ans.push_back(cur);
                    found = true;
                    continue;
                }

                if (found)
                    continue;

                for (int i = 0; i < (int)cur.size(); i++) {
                    if (cur[i] != '(' && cur[i] != ')')
                        continue;

                    string nxt = cur.substr(0, i) + cur.substr(i + 1);

                    if (!vis.count(nxt)) {
                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }

            if (found)
                break;
        }

        if (ans.empty())
            return {""};
        return ans;
    }
};
