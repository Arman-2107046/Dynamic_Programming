#include <bits/stdc++.h>
using namespace std; // tabulation solution
int main()
{
    vector<vector<int>> matrix =
        {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}};

    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e7;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int left = matrix[i][j];
            if (j>=1)
                left += dp[i - 1][j - 1];
            else
            {
                left += -1e9;
            }

            int right = matrix[i][j];
            if (j< m-1)
                right += dp[i - 1][j + 1];
            else
            {
                right += -1e9;
            }

            dp[i][j] = max(up, max(left, right));
        }
    }

    
    for (int k = 0; k < 3; k++)
    {
        maxi = max(maxi, dp[n - 1][k]);
    }
    cout << maxi << endl;
}
