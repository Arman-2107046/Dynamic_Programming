/*#include <bits/stdc++.h>
using namespace std; // tabulation

int f( vector<int> &arr, vector<int> &dp)
{
int n=arr.size();
dp[0]=arr[0];


for(int i=1;i<n;i++)
{
    int take=arr[i];
    if(i>1)
    {
        take+=dp[i-2];
    }

    int not_take=0+dp[i-1];

    dp[i]=max(take,not_take);
}

return dp[n-1];
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

    int ans1 = f( temp1, dp);
    int ans2 = f( temp2, dp);
    cout << max(ans1, ans2) << endl;
}
*/

#include <bits/stdc++.h>
using namespace std; // tabulation with space optimization

int f(vector<int> &arr)
{
    int n = arr.size();

    int prev1 = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
        {
            take += prev2;
        }

        int not_take = 0 + prev1;

        int curr = max(take, not_take);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> house = {4, 3, 7, 2, 6};

    int n = house.size();

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(house[i]);

        if (i != n - 1)
            temp2.push_back(house[i]);
    }

    int ans1 = f(temp1);
    int ans2 = f(temp2);
    cout << max(ans1, ans2) << endl;
}