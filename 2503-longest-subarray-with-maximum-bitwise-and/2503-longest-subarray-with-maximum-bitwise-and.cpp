class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int max_val = 0;
        if (!nums.empty()) {
            max_val = *std::max_element(nums.begin(), nums.end());
        }
        
        int max_length = 0;
        int current_length = 0;
        
        for (int num : nums) {
            if (num == max_val) {
                current_length++;
            } else {
                current_length = 0;
            }
            max_length = std::max(max_length, current_length);
        }        
        return max_length;
    }
};