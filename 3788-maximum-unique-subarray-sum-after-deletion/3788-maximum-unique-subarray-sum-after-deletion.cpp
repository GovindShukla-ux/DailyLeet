class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
        long long max_overall_sum = numeric_limits<long long>::min(); 

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                unordered_set<int> unique_elements_in_window;
                long long current_window_sum_positives = 0;
                int max_unique_val_in_window = numeric_limits<int>::min();
                bool has_positive_unique = false;

                for (int k = i; k <= j; ++k) {
                    if (unique_elements_in_window.find(nums[k]) == unique_elements_in_window.end()) {
                        unique_elements_in_window.insert(nums[k]);
                        max_unique_val_in_window = max(max_unique_val_in_window, nums[k]);
                        if (nums[k] > 0) {
                            current_window_sum_positives += nums[k];
                            has_positive_unique = true;
                        }
                    }
                }

                long long current_selected_subarray_sum;
                if (has_positive_unique) {
                    current_selected_subarray_sum = current_window_sum_positives;
                } else {
                    current_selected_subarray_sum = max_unique_val_in_window;
                }
                
                max_overall_sum = max(max_overall_sum, current_selected_subarray_sum);
            }
        }
        return static_cast<int>(max_overall_sum);
    }
};