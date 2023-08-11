#include <bits/stdc++.h>
using namespace std; // memoization

int f(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return arr[0];

    if (ind < 0)
        return 0;

    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int take = arr[ind] + f(ind - 2, arr, dp);
    int not_take = 0 + f(ind - 1, arr, dp);

    return dp[ind] = max(take, not_take);
}

int main()
{
    vector<int> house = {4, 3, 7, 2, 6};

    int n = house.size();

    vector<int> dp(n, -1);
    dp[0] = house[0];

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(house[i]);

        if (i != n - 1)
            temp2.push_back(house[i]);
    }

    int ans1 = f(n - 1, temp1, dp);
    int ans2 = f(n - 1, temp2, dp);
    cout << max(ans1, ans2) << endl;
}