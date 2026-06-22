class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = 0;

        while (left < right) {
            int width = right - left - 1;   // bars between them
            int area = min(height[left], height[right]) * width;
            ans = max(ans, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};
