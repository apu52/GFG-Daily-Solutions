class Solution {
  public:
    int maxXor(vector<int> &arr) {
        // code here
        int res = 0;
        int mask = 0;
        int curr = 0;
        
        for(int i = 30; i >= 0; i--)
        {
            set<int> st;
            
            mask |= (1 << i);
            for(auto x : arr)
            {
                st.insert(x & mask);
            }
            
            curr |= (1 << i);
            bool f = 0;
            
            for(auto x : st)
            {
                if(st.find(curr ^ x) != st.end())
                {
                    f = 1;
                    break;
                }
            }
            
            if(!f) curr ^= (1 << i);
            
            res = max(res, curr);
        }
        return res;
    }
};
