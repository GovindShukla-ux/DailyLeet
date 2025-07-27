class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        std::vector<int> v;
        v.push_back(nums[0]);
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != v.back()) {
                v.push_back(nums[i]);
            }
        }

        if (v.size() < 3) {
            return 0;
        }

        int count = 0;
        for (size_t i = 1; i < v.size() - 1; ++i) {
            bool is_hill = v[i] > v[i - 1] && v[i] > v[i + 1];
            bool is_valley = v[i] < v[i - 1] && v[i] < v[i + 1];
            if (is_hill || is_valley) {
                count++;
            }
        }
        return count;
    }
};