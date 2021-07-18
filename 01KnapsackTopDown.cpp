#include <bits/stdc++.h>
using namespace std;

//0-1 Knapsack Problem Top-Down Method

int knapsack(int[],int[],int,int);

int main()
{
  int n,w;
  cin>>n>>w;
  int wt[n],val[n];

  for(int i=0;i<n;i++)
  {
      cin>>wt[i];
  }
  for(int i=0;i<n;i++)
  {
      cin>>val[i];
  }
  int dp[n+1][w+1];//(w+1) is the columns.

  memset(dp,0,sizeof(dp));

  for(int i=0;i<n+1;i++)
  {
      for(int j=0;j<w+1;j++)
      {
          if(i==0||j==0)
          {
              dp[i][j] = 0;
          }
      }
  }
  for(int i=1;i<n+1;i++)
  {
      for(int j=1;j<w+1;j++)
      {
          if(wt[i-1]<=j)
          {
              dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
          }
          else
          {
              dp[i][j] = dp[i-1][j];
          }
      }
  }

  cout<<dp[n][w];

  return 0;
}
