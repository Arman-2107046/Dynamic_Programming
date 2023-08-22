#include <bits/stdc++.h>
using namespace std; // memoization solution

int f(vector<vector<int>> &matrix, int i, int j, vector<vector<int>>dp)
{
    if (j < 0 || j > matrix[0].size() - 1)
    {
        return -1e9;
    }

    if (i == 0)
    {
        return matrix[i][j];
    }

    int up = matrix[i][j] + f(matrix, i - 1, j,dp);

    int left = matrix[i][j] + f(matrix, i - 1, j - 1,dp);

    int right = matrix[i][j] + f(matrix, i - 1, j + 1,dp);

    return dp[i][j]=max(up, max(left, right));
}
int main()
{
    vector<vector<int>> matrix =
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}};

    int m = matrix.size();
    int n = matrix[0].size();
    int maxi = -1e7;

  vector<vector<int>>dp(m,vector<int>(n,-1));
    for (int k = 0; k < 3; k++)
    {
        maxi = max(maxi, f(matrix, m - 1, k,dp));
    }
    cout << maxi << endl;
}
