class Solution 
{    
    public: 
     vector<int> repeatedRows(vector<vector<int>> &arr, int m, int n){ 
        set<vector<int>>st; 
        vector<int>ans; 
        int temp = 0; 
        for (int i=0;i<m;i++){ 
            st.insert(arr[i]); 
            if (st.size() + temp - 1 != i){ 
                ans.push_back(i); 
                temp++; 
            } 
        } 
        return ans; 
    }  
};
