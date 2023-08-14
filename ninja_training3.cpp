#include <bits/stdc++.h>
using namespace std; // tabulation

int main()
{
    int n = 4;

    vector<vector<int>> points = {{2, 1, 3},
                                  {3, 4, 6},
                                  {10, 1, 6},
                                  {8, 3, 7}};

    vector<vector<int>> dp(n, vector<int>(3, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 3; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
}
