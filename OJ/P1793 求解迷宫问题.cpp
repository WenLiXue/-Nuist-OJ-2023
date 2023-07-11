#include<iostream>
#include<cstdio>
using namespace std;
char arr[10][10];				//�洢ͼ
int visit[10][10];				//�ж��Ƿ���ʹ���ǰ�㲢�Ҵ洢����ҵ���ͨ·��0����δ���ʣ�1�����ѷ���
int dx[] = { 0,1,0,-1 };		//�������飬����x�ķ���
int dy[] = { 1,0,-1,0 };		//�������飬����y�ķ���
void dfs(int x, int y)			//����
{
	if (x == 7 && y == 7)			//�����жϱ�־�������յ��ʱ��ͽ���������visit���飬���Ϊ1����Ϊ����ͨ·���ϵ�һ�㣬����ո�
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
	int k;						//�������������ĸ�����������
	for (k = 0; k < 4; k++)
	{
		if (arr[x + dx[k]][y + dy[k]] == 'O' && visit[x + dx[k]][y + dy[k]] == 0)				//�ж���������һ���ڵ����ͨ�У�����û�з��ʹ�
		{
			visit[x + dx[k]][y + dy[k]] = 1;		//��ýڵ�Ϊ�ѷ��ʣ������ýڵ�
			dfs(x + dx[k], y + dy[k]);
			visit[x + dx[k]][y + dy[k]] = 0;	//����
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
	visit[0][0] = 1;			//��Ϊ����㿪ʼ������Ҫ�������Ϊ�ѷ��ʡ�
	dfs(0, 0);
	return 0;
}
