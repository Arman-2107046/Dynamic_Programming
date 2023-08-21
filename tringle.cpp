/*class Solution
{
private:
    int f(int i, int j, int n, vector<vector < int>> &arr, vector<vector<int>>&dp)
    {
        if(i==n-1)
        {
            return arr[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        else
        {
            int down=arr[i][j]+f(i+1,j,n,arr,dp);
            int diag=arr[i][j]+f(i+1,j+1,n,arr,dp);

            return dp[i][j]=min(down,diag);
        }
    }
    public:
        int minimumTotal(vector<vector < int>> &triangle)
        {
            int n = triangle.size();
            vector<vector<int>>dp(n,vector<int>(n,-1));
            return f(0,0,n,triangle,dp);
            
        }
};
*/