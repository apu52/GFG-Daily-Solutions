class Solution {
  public:
    vector<int> reducePairs(vector<int>& v) {
        int n=v.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
           if(st.empty())
           {
               st.push(v[i]);
               continue;
           }
           bool insert=1;
           while(!st.empty() && 1LL*v[i]*st.top()<0)
           {
               if(abs(v[i])<abs(st.top())) {insert=0;break;}
               else if(abs(v[i])==abs(st.top())) {st.pop();insert=0;break;}
               else st.pop();
           }
           if(insert) st.push(v[i]);
        }
        vector<int>ans;
        while(!st.empty()){ans.push_back(st.top()); st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
