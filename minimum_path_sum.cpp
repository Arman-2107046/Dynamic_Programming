#include <bits/stdc++.h>
using namespace std;//memoization soslution

int f(int i, int j, vector<vector<int>> &grid,vector<vector<int>>&dp)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return 1e9;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int up = grid[i][j] + f(i - 1, j, grid,dp);
    int left = grid[i][j] + f(i, j - 1, grid,dp);

    return dp[i][j]=min(up, left);
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    cout << f(m - 1, n - 1, grid,dp) << endl;

    return 0;
}
