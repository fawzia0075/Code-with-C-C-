#include<iostream>
using namespace std;

int findMax(int n1,int n2)
{
    if(n1>n2)
        return n1;
    else
        return n2;
}

int knapsack(int w,int wt[],int val[],int n)
{
    int k[n+1][w+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            if(i==0 || j==0)
            {
                k[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                k[i][j]=findMax(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            }
            else
            {
                k[i][j]=k[i-1][j];
            }
        }
    }
    return k[n][w];
}

int main()
{
    int val[]={12,10,20,15};
    int wt[]={2,1,3,2};
    int w=5;
    int len=sizeof(val)/sizeof(val[0]);

    cout<<"Max profit:"<<knapsack(w,wt,val,len);
    return 0;
}
