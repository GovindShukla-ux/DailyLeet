class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> freqMap;
        for (int num : arr) 
        {
            freqMap[num]++;
        }

        int lucky = -1;

        for (auto const& pair : freqMap) 
        {
            int num = pair.first;
            int freq = pair.second;            
            if (num == freq) 
            {
                lucky = max(lucky, num);
            }
        }
       return lucky;
    }
};