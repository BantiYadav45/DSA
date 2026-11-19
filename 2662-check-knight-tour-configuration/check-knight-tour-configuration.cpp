
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {

        int n = grid.size();

        // Knight must start at top-left
        if (grid[0][0] != 0) {
            return false;
        }

        vector<pair<int, int>> pos(n * n);

        // Store the position of every number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        // Check every consecutive move
        for (int k = 1; k < n * n; k++) {

            int r1 = pos[k - 1].first;
            int c1 = pos[k - 1].second;

            int r2 = pos[k].first;
            int c2 = pos[k].second;

            int dr = abs(r2 - r1);
            int dc = abs(c2 - c1);

            // Valid knight move
            if (!((dr == 2 && dc == 1) ||
                  (dr == 1 && dc == 2))) {
                return false;
            }
        }

        return true;
    }
};
