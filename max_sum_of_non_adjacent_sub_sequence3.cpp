/*#include <bits/stdc++.h>
using namespace std; // using tabulation

int main()
{

    int n = 4;
    vector<int> nums = {2, 1, 4, 9};

    vector<int> dp(n, -1);

    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
        {
            take += dp[i - 2];
        }

        int not_take = 0 + dp[i - 1];

        dp[i] = max(take, not_take);
    }

    cout << dp[n-1] << endl;
}
*/

#include <bits/stdc++.h>
using namespace std; // using tabulation space optimization

int main()
{

    int n = 4;
    vector<int> nums = {2, 1, 4, 9};

    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i <= n; i++)
    {
        int take = nums[i];
        if(i>1)
        {
            take+=prev2;
        }

        int not_take = prev1;

        int curr = max(take, not_take);
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;
}