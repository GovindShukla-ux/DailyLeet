class Solution {
public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int max_or_value = 0;
        for (int num : nums) 
        {
            max_or_value |= num;
        }

        int count = 0;
        int n = nums.size();
        for (int i = 1; i < (1 << n); ++i) 
        {
            int current_or = 0;
            for (int j = 0; j < n; ++j) 
            {
                if ((i >> j) & 1) {
                    current_or |= nums[j];
                }
            }
            if (current_or == max_or_value) {
                count++;
            }
        }
        return count;
    }
};