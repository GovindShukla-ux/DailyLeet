class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1 || s.empty()) 
        {
            return s;
        }

        vector<string> rows(numRows);

        int current_row = 0;
        bool going_down = false;

        for (char c : s) 
        {
            rows[current_row] += c;

            if (current_row == 0) 
            {
                going_down = true;
            } 
            else if (current_row == numRows - 1) 
            {
                going_down = false;
            }

            if (going_down) 
            {
                current_row++;
            } 
            else 
            {
                current_row--;
            }
        }

        string result = "";
        for (const string& row : rows) 
        {
            result += row;
        }
     return result;
    }
};