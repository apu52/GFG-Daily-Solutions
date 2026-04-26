class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string st = "";
        int n = s.size();
        int i=0;
        while(i<n)
        {
            if(s[i]==' ') 
            {
                i++;
            }

            else
            {
                st.push_back(s[i]);
                i++;
            }
        }
        return st;
    }
};
