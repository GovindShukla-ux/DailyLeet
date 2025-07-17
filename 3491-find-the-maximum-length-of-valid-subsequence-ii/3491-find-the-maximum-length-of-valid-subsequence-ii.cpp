class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int maxLen = 1;

        for (int i = 1; i < n; ++i) 
        {
            for (int j = 0; j < i; ++j) 
            {
                int mod = (nums[j] + nums[i]) % k;

                int len = 2;
                if (dp[j].count(mod)) 
                {
                    len = dp[j][mod] + 1;
                }

                if (dp[i].count(mod)) 
                {
                    dp[i][mod] = max(dp[i][mod], len);
                } 
                else 
                {
                    dp[i][mod] = len;
                }
                maxLen = max(maxLen, dp[i][mod]);
            }
        }
        return maxLen;
    }
};
