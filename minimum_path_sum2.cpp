#include <bits/stdc++.h>
using namespace std; // tabulation soslution

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));//must use else!!!!

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }

            else
            {
            int up = grid[i][j];
            if (i > 0)
                up += dp[i - 1][j];
            else
                up += 1e9;

            int left = grid[i][j];
            if (j > 0)
                left += dp[i][j - 1];
            else
                left += 1e9;

            dp[i][j] = min(up, left);
            }
        }
    }
    cout << dp[m - 1][n - 1] << endl;

    return 0;
}
