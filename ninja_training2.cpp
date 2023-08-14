#include <bits/stdc++.h>
using namespace std; // memoization solution

int f(int day, int last, vector<vector<int>> &points,vector<vector<int>>&dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)
    {
        return dp[day][last];
    }
    
    int maxi = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + f(day - 1, i, points,dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last]=maxi;
}

int main()
{
    int n = 4;
    vector<vector<int>> dp(n, vector<int>(4, -1));

    vector<vector<int>> points = {{2, 1, 3},
                                  {3, 4, 6},
                                  {10, 1, 6},
                                  {8, 3, 7}};

    cout << "max point is : " << f(n - 1, 3, points, dp) << endl; // Change the initial value of 'last' to 2
}
