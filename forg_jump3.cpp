/*#include <bits/stdc++.h>
using namespace std; // tabulation solution

int main()
{

    int n = 4;
    vector<int> heights = {10, 30, 20, 25};
    vector<int> dp(n + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;

        if (i <= 2)
        {
            right = dp[i - 2] + abs(heights[i - 2] - heights[i]);
        }
        dp[i] = min(left, right);
    }

    cout<<dp[n-1]<<endl;
}*/

#include <bits/stdc++.h>
using namespace std; // tabulation solution space optimization

int main()
{

    int n = 4;
    vector<int> heights = {10, 30, 20, 25};

    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;

        if (i >= 2)
        {
            right = prev2 + abs(heights[i - 2] - heights[i]);
        }
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }

    cout << prev << endl;
}