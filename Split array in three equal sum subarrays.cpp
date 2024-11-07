class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        int total_sum = 0;
        for (int num : arr) {
            total_sum += num;
        }
        
        if (total_sum % 3 != 0) {
            return {-1, -1};
        }
        
        int target_sum = total_sum / 3;
        int current_sum = 0;
        int first_index = -1, second_index = -1;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            current_sum += arr[i];
            
            if (current_sum == target_sum && first_index == -1) {
                first_index = i;
            }
            
            if (current_sum == 2 * target_sum && first_index != -1) {
                second_index = i;
                break;
            }
        }
        
        if (first_index != -1 && second_index != -1) {
            int last_part_sum = 0;
            for (int i = second_index + 1; i < n; i++) {
                last_part_sum += arr[i];
            }
            if (last_part_sum == target_sum) {
                return {first_index, second_index};
            }
        }
        
        return {-1, -1};
    }
};
