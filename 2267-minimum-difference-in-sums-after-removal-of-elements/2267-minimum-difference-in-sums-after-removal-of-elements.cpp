class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int n = nums.size() / 3;
        int total = nums.size();
        vector<long long> left(total, 0), right(total, 0);

        priority_queue<int> maxHeap;
        long long sumLeft = 0;
        for (int i = 0; i < 2 * n; ++i) 
        {
            sumLeft += nums[i];
            maxHeap.push(nums[i]);
            if (maxHeap.size() > n) 
            {
                sumLeft -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n) left[i] = sumLeft;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sumRight = 0;
        for (int i = total - 1; i >= n; --i) 
        {
            sumRight += nums[i];
            minHeap.push(nums[i]);
            if (minHeap.size() > n) 
            {
                sumRight -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n) right[i] = sumRight;
        }

        long long result = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) 
        {
            result = min(result, left[i] - right[i + 1]);
        }

        return result;
    }
};
