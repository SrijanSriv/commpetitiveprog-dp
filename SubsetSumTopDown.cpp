#include <bits/stdc++.h>
using namespace std;

//Subset Sum Problem Top-Down


int main()
{
  int n,sum;
  cin>>n>>sum;
  int wt[n];

  for(int i=0;i<n;i++)
  {
      cin>>wt[i];
  }

  bool dp[n+1][sum+1];//(sum+1) is the columns.

  for(int i=0;i<n+1;i++)
  {
      for(int j=0;j<sum+1;j++)
      {
          if(i==0)
          {
              dp[i][j] = false;
          }
          if(j==0)
          {
              dp[i][j] = true;
          }
      }
  }
  for(int i=1;i<n+1;i++)
  {
      for(int j=1;j<sum+1;j++)
      {
          if(wt[i-1]<=j)
          {
              dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j];
          }
          else
          {
              dp[i][j] = dp[i-1][j];
          }
      }
  }

  cout<<dp[n][sum];// 1 is true, 0 is false.

  return 0;
}
