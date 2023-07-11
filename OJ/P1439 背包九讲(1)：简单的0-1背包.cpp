//本题是一道经典的dp题目
#include<iostream>
using namespace std;
typedef struct box						//记录每个物品的重量和体积
{
	int val;
	int weight;
}box;
box arr[100];							//存储所有的物品
int dp[100][20000];						//dp[i][j]代表在背包容量为j的情况下，装i个物品的最大价值
int main()
{
	int n, v;
	while (cin >> v >> n)
	{
		int i, j;
		for (i = 1; i <= n; i++)
		{
			cin >> arr[i].weight >> arr[i].val;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j <= v; j++)
			{
			//此处是dp的精髓所在，就是写状态转移方程，根据上面所述dp[i][j]代表的是背包容量为j的情况下，装i个物品的最大价值
			//也就是对于第i个物品，我们可以选择装或者不装。如果我们要装第i个物品的话，我们首先要保证当前的背包容量足够装下第i个物品，那么此时的最佳价值应该是dp[i-1][j-arr[i].weight]+arr[i].val.
			//如果不装，那么就等于dp[i-1][j]
			//取两者的最大值，就是dp[i][j]，最后dp[n][v]就是最大价值
				if (j >= arr[i].weight)		dp[i][j] = max(dp[i - 1][j], arr[i].val + dp[i - 1][j - arr[i].weight]);
				else									dp[i][j] = dp[i - 1][j];
			}
		}
		cout << dp[n][v] << endl;
		for (i = 1; i <= n; i++)			//由于是多组输入，所以每一次循环后，就要把dp数组归零
		{
			for (j = 0; j <= v; j++)
			{
				dp[i][j] = 0;
			}
		}
	}
	
	return 0;
}

