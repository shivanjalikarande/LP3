#include <iostream>
#include <vector>
using namespace std;

//Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and bound strategy.


class Item
{
    public:
        int weight;
        int profit;
        Item()
        {
            weight = 0;
            profit = 0;
        }
        Item(int w, int p)
        {
            weight = w;
            profit = p;
        }
};

//1. Recursive Solution
int knapsack_rec(int* wt, int* profit, int W, int n)
{
    if(W == 0 || n == 0) return 0;

    int take = 0;

    if(wt[n-1] <= W)
    {
        take = knapsack_rec(wt, profit, W - wt[n-1], n-1) + profit[n-1];
    }

    int notTake = knapsack_rec(wt,profit,W,n-1);

    return max(take, notTake);
}


//2. Tabulation
int knapsack_dp(int* wt, int* profit, int W, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if(wt[i-1] <= w)
            {
                dp[i][w] = max(profit[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][W];
}


int main()
{
    int W;
    cout<<"Enter weight of bag: ";
    cin>>W;

    int n;
    cout<<"\nEnter no of items: ";
    cin>>n;

    int* wt = new int[n];
    int* profit = new int[n];

    cout<<"\n\nEnter items weights and respective profit values"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"Item "<<(i+1)<<": ";
        cin>>wt[i]>>profit[i];
    }

    cout<<"\nMaximum Profit(Recursive): "<<knapsack_rec(wt,profit,W,n);
    cout<<"\n\nMaximum Profit(Tabulation): "<<knapsack_dp(wt,profit,W,n);


    return 0;
}