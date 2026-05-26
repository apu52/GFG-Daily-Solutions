class Solution {
public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();

        int zeros = 0;
        for(int x : arr) {
            if(x == 0) zeros++;
        }

        int onesLeft = 0;
        int ans = zeros;

        for(int i = 0; i < n; i++) {

            if(arr[i] == 1)
                onesLeft++;

            else
                zeros--;

            ans = min(ans, onesLeft + zeros);
        }

        return ans;
    }
};
