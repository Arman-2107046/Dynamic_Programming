#include <bits/stdc++.h>
using namespace std; // using recursion

int f(int ind, vector<int> &nums)
{
    if (ind == 0)
        return nums[0];
    if (ind < 1)
        return 0;

    int pick = nums[ind] + f(ind - 2, nums);
    int not_pick = 0 + f(ind - 1, nums);

    return max(pick, not_pick);
}
int main()
{

    int n = 4;
    vector<int> nums = {2, 1, 4, 9};

    cout << f(n - 1, nums);
}