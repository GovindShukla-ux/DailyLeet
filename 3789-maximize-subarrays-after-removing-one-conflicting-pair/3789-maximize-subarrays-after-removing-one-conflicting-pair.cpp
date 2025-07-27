class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long valid = 0;
        int maxL = 0, secondMaxL = 0;
        vector<long long> gains(n + 2);
        vector<vector<int>> conflicts(n + 2);

        for (auto &p : conflictingPairs) {
            int a = p[0], b = p[1];
            int r = max(a, b), l = min(a, b);
            conflicts[r].push_back(l);
        }

        for (int right = 1; right <= n; right++) {
            for (int left : conflicts[right]) {
                if (left > maxL) {
                    secondMaxL = maxL;
                    maxL = left;
                } else if (left > secondMaxL) {
                    secondMaxL = left;
                }
            }
            valid += (right - maxL);
            gains[maxL] += (maxL - secondMaxL);
        }

        return valid + *max_element(gains.begin(), gains.end());
    }
};