class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) 
    {
        std::unordered_set<int> seen;
        int left = 0;
        long long current_sum = 0;
        long long max_sum = 0;

        for (int right = 0; right < nums.size(); ++right) 
        {
            while (seen.count(nums[right])) 
            {
                current_sum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }

            seen.insert(nums[right]);
            current_sum += nums[right];

            max_sum = std::max(max_sum, current_sum);
        }
        return static_cast<int>(max_sum);
    }
};