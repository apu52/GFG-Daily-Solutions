class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        //complete the function
        int n = arr.size();

        // Step 1: Modify the array according to the rule
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] != 0 && arr[i] == arr[i + 1]) {
                arr[i] *= 2;  
                arr[i + 1] = 0;  
            }
        }

        // Step 2: Rearrange the array by moving non-zero elements to the front
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                result.push_back(arr[i]);
            }
        }

        // Step 3: Add the remaining zeros at the end
        while (result.size() < n) {
            result.push_back(0);
        }

        return result;
    }
};
