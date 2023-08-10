#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int>&dp)//memoization solution
{
    if(n<=1)
    return n;

    if(dp[n]!=-1)
    return dp[n];

    return dp[n]=f(n-1,dp)+f(n-2,dp);
}
int main()//fibonacci using dp
{
int n;
cin>>n;
vector<int>dp(n+1,-1);

cout<<f(n,dp);

}