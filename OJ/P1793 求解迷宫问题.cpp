#include<iostream>
#include<cstdio>
using namespace std;
char arr[10][10];				//存储图
int visit[10][10];				//判断是否访问过当前点并且存储最后找到的通路，0代表未访问，1代表已访问
int dx[] = { 0,1,0,-1 };		//方向数组，控制x的方向
int dy[] = { 1,0,-1,0 };		//方向数组，控制y的方向
void dfs(int x, int y)			//深搜
{
	if (x == 7 && y == 7)			//结束判断标志，到达终点的时候就结束，遍历visit数组，如果为1，则为最终通路上上的一点，输出空格
	{
		int i, j;
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (visit[i][j] == 1)			printf(" ");
				else printf("%c", arr[i][j]);
			}
			printf("\n");
		}
		return;
	}
	int k;						//根据上下左右四个方向来遍历
	for (k = 0; k < 4; k++)
	{
		if (arr[x + dx[k]][y + dy[k]] == 'O' && visit[x + dx[k]][y + dy[k]] == 0)				//判断条件，下一个节点可以通行，并且没有访问过
		{
			visit[x + dx[k]][y + dy[k]] = 1;		//设该节点为已访问，遍历该节点
			dfs(x + dx[k], y + dy[k]);
			visit[x + dx[k]][y + dy[k]] = 0;	//回溯
		}
	}
}
int main()
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	visit[0][0] = 1;			//因为从起点开始，所以要设置起点为已访问。
	dfs(0, 0);
	return 0;
}
