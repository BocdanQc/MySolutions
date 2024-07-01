#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int minimum = 0;

        const int ROWS = static_cast<int>(triangle.size());

        for (int i = 1; i < ROWS; ++i) {
            const int N = triangle[i].size();
            for (int j = 0; j < N; ++j) {
                if (j == 0) {
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
                }
                else if (j == N - 1) {
                    triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        if (ROWS > 0) {
            minimum = *min_element(triangle[ROWS - 1].begin(), triangle[ROWS - 1].end());
        }
        return minimum;
    }
};
