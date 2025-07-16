class Solution {
public:
    int maximumLength(vector<int>& nums) 
    {
        int n = nums.size();
        if (n <= 1) return n;
        
        int maxLength = 1;
        
        int evenCount = 0;
        for (int num : nums) {
            if (num % 2 == 0) evenCount++;
        }
        maxLength = max(maxLength, evenCount);
        
        int oddCount = 0;
        for (int num : nums) {
            if (num % 2 == 1) oddCount++;
        }
        maxLength = max(maxLength, oddCount);
        

        int length = 0;
        bool expectingEven = true;
        for (int num : nums) {
            if ((num % 2 == 0) == expectingEven) {
                length++;
                expectingEven = !expectingEven;
            }
        }
        maxLength = max(maxLength, length);

        length = 0;
        bool expectingOdd = true;
        for (int num : nums) {
            if ((num % 2 == 1) == expectingOdd) {
                length++;
                expectingOdd = !expectingOdd;
            }
        }
        maxLength = max(maxLength, length);
        
        return maxLength;
    }
};
