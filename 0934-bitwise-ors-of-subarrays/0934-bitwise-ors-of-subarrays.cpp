class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) 
    {
        unordered_set<int> all_possible_ors;
        unordered_set<int> or_ending_at_prev;

        for (int a : arr) 
        {
            unordered_set<int> or_ending_here; 
            or_ending_here.insert(a);

            for (int prev_or : or_ending_at_prev) 
            {
                or_ending_here.insert(prev_or | a);
            }
            
            for (int current_or : or_ending_here) 
            {
                all_possible_ors.insert(current_or);
            }
            or_ending_at_prev = or_ending_here;
        }
        return all_possible_ors.size();
    }
};