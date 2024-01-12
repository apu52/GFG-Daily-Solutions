#include <queue>
#include <stack>

class Solution
{
public:

    
    std::queue<int> modifyQueue(std::queue<int> q, int k) {
        if (k <= 0 || k > q.size()) {
            
            return q;
        }

        std::stack<int> s;

        
        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        
        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        
        for (int i = 0; i < q.size() - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
