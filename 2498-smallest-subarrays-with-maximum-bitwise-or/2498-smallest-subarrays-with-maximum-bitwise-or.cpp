class Solution {
public:
    std::vector<int> smallestSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);
        std::vector<int> last_occurrence_of_bit(30, -1); 

        for (int i = n - 1; i >= 0; --i) {
            int max_reach_index = i; 

            for (int bit_pos = 0; bit_pos < 30; ++bit_pos) {
                if ((nums[i] >> bit_pos) & 1) {
                    last_occurrence_of_bit[bit_pos] = i;
                }

                if (last_occurrence_of_bit[bit_pos] != -1) {
                    max_reach_index = std::max(max_reach_index, last_occurrence_of_bit[bit_pos]);
                }
            }
            
            answer[i] = max_reach_index - i + 1;
        }

        return answer;
    }
};