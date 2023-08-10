/*#include<bits/stdc++.h>
using namespace std;//using tabulation

int main()
{
int n;
cin>>n;

vector<int>dp(n+1,-1);

  dp[0]=dp[1]=1;

  for(int i=2;i<=n;i++)
  {
    dp[i]=dp[i-1]+dp[i-2];
  }

  cout<<dp[n];

}
*/

#include <bits/stdc++.h>
using namespace std; // using tabulation optimizing space

int main()
{
    int n;
    cin >> n;


    int prev1=1;
    int prev2=1;

    for (int i = 2; i <= n; i++)
    {
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }

    cout << prev1;
}