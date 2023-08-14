#include <bits/stdc++.h>
using namespace std; // recursive solution

int f(int day, int last, vector<vector<int>> &points)
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

    int maxi = INT_MIN;

    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + f(day - 1, i, points);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int main()
{
    int n = 4;
    vector<vector<int>> points = {{2, 1, 3},
                                  {3, 4, 6},
                                  {10, 1, 6},
                                  {8, 3, 7}};

    cout << "max point is : " << f(n - 1, 3, points) << endl;
}
