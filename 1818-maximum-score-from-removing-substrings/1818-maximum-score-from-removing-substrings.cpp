class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        if (x > y) 
        {
            string temp = removeAndScore(s, "ab", x, totalScore);
            removeAndScore(temp, "ba", y, totalScore);
        } 
        else 
        {
            string temp = removeAndScore(s, "ba", y, totalScore);
            removeAndScore(temp, "ab", x, totalScore);
        }
        return totalScore;
    }

private:
    string removeAndScore(string& s, const string& sub, int scorePerRemoval, int& currentScore) {
        string result;
        for (char c : s) {
            result.push_back(c);
            if (result.length() >= 2 && result.substr(result.length() - 2) == sub) {
                result.pop_back();
                result.pop_back();
                currentScore += scorePerRemoval;
            }
        }
        return result;
    }
};