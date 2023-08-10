#include <bits/stdc++.h>
using namespace std; // memoization

int f(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main() // climbing stairs
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp) << endl;
}
