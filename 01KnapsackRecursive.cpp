#include <bits/stdc++.h>
using namespace std;

//0-1 Knapsack Problem

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

  cout<<knapsack(wt,val,w,n);

  return 0;
}

int knapsack(int wt[],int val[],int w,int n)
{
    if(w==0||n==0)
    {
        return 0;
    }
    else
    {
        if(wt[n-1]<=w)
        {
            return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
        }
        else
        {
            return knapsack(wt,val,w,n-1);
        }
    }
}
