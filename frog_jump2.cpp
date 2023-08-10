#include <bits/stdc++.h>
using namespace std; // memoization solution

int f(int ind, vector<int>&heights,vector<int>&dp)
{
if(ind==0)
return 0;
if(dp[ind]!=-1)
{
    return dp[ind];
}
int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
int right=INT_MAX;

if(ind>=2)
{
    right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
}

return min(left,right);

}
int main()
{
    int n = 4;
    vector<int> heights = {10, 30, 20, 25};
    vector<int> dp(n + 1, -1);

    cout << f(n - 1, heights,dp);
}