#include <bits/stdc++.h>
using namespace std; // using memoization

int f(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[0];
    if (ind < 1)
        return 0;
        
    if(dp[ind]!=-1)
    return dp[ind];

    int pick = nums[ind] + f(ind - 2, nums, dp);
    int not_pick = 0 + f(ind - 1, nums, dp);
    return dp[ind]=max(pick, not_pick);
}

int main()
{

    int n = 4;
    vector<int> nums = {2, 1, 4, 9};

    vector<int> dp(n, -1);
    cout << f(n - 1, nums, dp);
}