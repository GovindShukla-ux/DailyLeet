class Solution {
public:
    int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
        int n = nums.size();
        std::vector<std::vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        std::vector<int> subtree_xor(n);
        std::vector<int> parent(n, -1);
        std::vector<int> entry_time(n);
        std::vector<int> exit_time(n);
        int timer = 0;

        std::function<void(int, int)> dfs = 
            [&](int u, int p) {
            parent[u] = p;
            entry_time[u] = timer++;
            subtree_xor[u] = nums[u];
            for (int v : adj[u]) {
                if (v == p) continue;
                dfs(v, u);
                subtree_xor[u] ^= subtree_xor[v];
            }
            exit_time[u] = timer++;
        };

        dfs(0, -1);

        int min_score = -1;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int u1 = edges[i][0];
                int v1 = edges[i][1];
                int u2 = edges[j][0];
                int v2 = edges[j][1];

                // Ensure u1 is parent of v1
                if (parent[v1] != u1) std::swap(u1, v1);
                // Ensure u2 is parent of v2
                if (parent[v2] != u2) std::swap(u2, v2);

                int xor1, xor2, xor3;

                // Case 1: One edge is an ancestor of the other
                // Assume v1 is an ancestor of v2 (or v2 is in subtree of v1)
                if (entry_time[v1] <= entry_time[v2] && exit_time[v2] <= exit_time[v1]) {
                    // v2 is in the subtree of v1
                    xor1 = subtree_xor[v2];
                    xor2 = subtree_xor[v1] ^ subtree_xor[v2];
                    xor3 = subtree_xor[0] ^ subtree_xor[v1];
                } 
                // Assume v2 is an ancestor of v1 (or v1 is in subtree of v2)
                else if (entry_time[v2] <= entry_time[v1] && exit_time[v1] <= exit_time[v2]) {
                    // v1 is in the subtree of v2
                    xor1 = subtree_xor[v1];
                    xor2 = subtree_xor[v2] ^ subtree_xor[v1];
                    xor3 = subtree_xor[0] ^ subtree_xor[v2];
                }
                // Case 2: Edges are in different subtrees (or one is root and other is in its subtree but not directly connected)
                else {
                    xor1 = subtree_xor[v1];
                    xor2 = subtree_xor[v2];
                    xor3 = subtree_xor[0] ^ xor1 ^ xor2;
                }

                int current_max = std::max({xor1, xor2, xor3});
                int current_min = std::min({xor1, xor2, xor3});
                int current_score = current_max - current_min;

                if (min_score == -1 || current_score < min_score) {
                    min_score = current_score;
                }
            }
        }

        return min_score;
    }
};