class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_set<int> st;
        for(int i=0; i<arr.size(); i++)
        {
            if(st.find(arr[i]) != st.end())
                return true;
            st.insert(arr[i]);
            if(i >= k)
            {
                st.erase(st.find(arr[i-k]));
            }
        }
        return false;
    }
};
