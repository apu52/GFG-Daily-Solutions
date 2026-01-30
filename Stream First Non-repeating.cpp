class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        string res = "";
        
        unordered_map<char, int>mp;
        mp[s[0]]++;
        
        res = res + s[0];
        
        queue<char>q;
        q.push(s[0]);
        
        for(int i=1;i<s.size();i++)
        {
            mp[s[i]]++;
            
            if(mp[s[i]] == 1)
            {
                q.push(s[i]);
            }
            
            while(q.empty() == false && mp[q.front()] > 1)
            {
                q.pop();
            }
            
            if(q.empty())
            {
                res.push_back('#');
            }
            else
            {
                res.push_back(q.front());
            }
            
        }
        
        return res;
    }
};
