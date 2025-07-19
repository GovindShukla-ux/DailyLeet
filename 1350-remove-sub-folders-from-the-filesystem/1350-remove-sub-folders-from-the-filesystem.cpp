class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        if (folder.empty()) {
            return {}; 
        }

        vector<string> result;
        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); ++i) {
            const string& current_folder = folder[i];
            const string& last_parent = result.back();

            if (!(current_folder.rfind(last_parent, 0) == 0 && 
                  current_folder.length() > last_parent.length() && 
                  current_folder[last_parent.length()] == '/')) { 
                
                result.push_back(current_folder);
            }
        }

        return result;
    }
};