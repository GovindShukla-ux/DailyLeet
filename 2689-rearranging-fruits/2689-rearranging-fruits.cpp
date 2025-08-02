class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::unordered_map<int, int> counts;
        int min_val = 1e9 + 7;

        for (int fruit : basket1) {
            counts[fruit]++;
            min_val = std::min(min_val, fruit);
        }
        for (int fruit : basket2) {
            counts[fruit]--;
            min_val = std::min(min_val, fruit);
        }

        std::vector<int> surplus1;
        std::vector<int> surplus2;
        for (auto const& [fruit, count] : counts) {
            if (count % 2 != 0) {
                return -1;
            }
            if (count > 0) {
                for (int i = 0; i < count / 2; ++i) {
                    surplus1.push_back(fruit);
                }
            } else if (count < 0) {
                for (int i = 0; i < -count / 2; ++i) {
                    surplus2.push_back(fruit);
                }
            }
        }

        std::sort(surplus1.begin(), surplus1.end());
        std::sort(surplus2.begin(), surplus2.end());

        long long total_cost = 0;
        int swaps_needed = surplus1.size();

        for (int i = 0; i < swaps_needed; ++i) {
            total_cost += std::min(surplus1[i], surplus2[swaps_needed - 1 - i]);
        }
        
        long long direct_swap_cost = 0;
        for (int i = 0; i < surplus1.size(); ++i) {
            direct_swap_cost += std::min(surplus1[i], surplus2[i]);
        }
        
        std::vector<int> wrong_fruits;
        int num_swaps = 0;
        for (auto const& [fruit, count] : counts) {
            if (count > 0) {
                for (int i = 0; i < count / 2; ++i) {
                    wrong_fruits.push_back(fruit);
                }
            } else if (count < 0) {
                for (int i = 0; i < -count / 2; ++i) {
                    wrong_fruits.push_back(fruit);
                }
            }
        }

        std::sort(wrong_fruits.begin(), wrong_fruits.end());
        
        long long cost = 0;
        int half_size = wrong_fruits.size() / 2;
        
        for (int i = 0; i < half_size; ++i) {
            cost += std::min(wrong_fruits[i], 2 * min_val);
        }
        return cost;
    }
};