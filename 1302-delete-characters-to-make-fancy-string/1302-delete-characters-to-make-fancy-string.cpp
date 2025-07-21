class Solution {
public:
    string makeFancyString(string s)
    {
        if (s.length() < 3) 
        {
            return s; 
        }

        string result = "";
        result += s[0];
        result += s[1];

        for (int i = 2; i < s.length(); ++i) 
        {
            if (!(s[i] == result[result.length() - 1] && s[i] == result[result.length() - 2])) 
            {
                result += s[i];
            }
        }
        return result;
    }
};