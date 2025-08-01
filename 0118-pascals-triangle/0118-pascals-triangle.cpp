class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> triangle;
        if (numRows == 0) 
        {
            return triangle;
        }

        triangle.push_back({1});

        for (int i = 1; i < numRows; ++i) {
            vector<int> prev_row = triangle.back();
            vector<int> current_row;
            current_row.push_back(1);

            for (int j = 1; j < prev_row.size(); ++j) 
            {
                current_row.push_back(prev_row[j - 1] + prev_row[j]);
            }
            
            current_row.push_back(1);
            triangle.push_back(current_row);
        }
        return triangle;
    }
};