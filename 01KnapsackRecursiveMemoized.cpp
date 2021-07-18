#include <bits/stdc++.h>
using namespace std;

//0-1 Knapsack Problem Recursive Memoization done (Matrix is made for those elements that change after every recursive call)

int knapsack(int[],int[],int,int);
int dp[101][101];//(w+1) columns.

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

  memset(dp,(-1),sizeof(dp));

  cout<<knapsack(wt,val,w,n);

  return 0;
}

int knapsack(int wt[],int val[],int w,int n)
{
    if(w==0||n==0)
    {
        return 0;
    }
    if(dp[n][w]!=(-1))
    {
        return dp[n][w];
    }
    else
    {
        if(wt[n-1]<=w)
        {
            return dp[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
        }
        else
        {
            return dp[n][w] = knapsack(wt,val,w,n-1);
        }
    }
}
